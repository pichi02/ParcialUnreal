// Copyright Epic Games, Inc. All Rights Reserved.

#include "ParcialGameMode.h"

#include "NetworkMessage.h"
#include "ParcialCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AParcialGameMode::AParcialGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	delayTime = 0.5f;
	decayAmount = 35.0f;

	powerToWinMultiplier = 1.5f;
}

float AParcialGameMode::GetPowerToWIn() const
{
	return powerToWin;
}

void AParcialGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle powerDecayTimer;

	GetWorld()->GetTimerManager().SetTimer(powerDecayTimer, this, &AParcialGameMode::StartPowerLevelDecay, delayTime,
	                                       true);
	AParcialCharacter* character = Cast<AParcialCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (character)
	{
		powerToWin = character->GetBasePowerLevel() * powerToWinMultiplier;
	}

	if (mainHUDClass)
	{
		activeWidget = CreateWidget<UUserWidget>(GetWorld(), mainHUDClass);
		activeWidget->AddToViewport();
	}
}

void AParcialGameMode::StartPowerLevelDecay()
{
	AParcialCharacter* character = Cast<AParcialCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (character && character->GetCurrentPowerLevel() > 0.0f)
	{
		if (!character->GetWin() && character->GetIsAlive())
		{
			character->UpdateCurrentPowerLevel(-decayAmount);
		}
	}
}
