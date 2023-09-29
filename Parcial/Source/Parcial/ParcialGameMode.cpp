// Copyright Epic Games, Inc. All Rights Reserved.

#include "ParcialGameMode.h"
#include "ParcialCharacter.h"
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
}

void AParcialGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle powerDecayTimer;

	GetWorld()->GetTimerManager().SetTimer(powerDecayTimer, this, &AParcialGameMode::StartPowerLevelDecay, delayTime,
	                                       true);
}

void AParcialGameMode::StartPowerLevelDecay()
{
	AParcialCharacter* character = Cast<AParcialCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (character && character->GetCurrentPowerLevel() > 0.0f)
	{
		character->UpdateCurrentPowerLevel(-decayAmount);
	}
}
