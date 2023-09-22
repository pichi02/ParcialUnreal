// Copyright Epic Games, Inc. All Rights Reserved.

#include "ParcialGameMode.h"
#include "ParcialCharacter.h"
#include "UObject/ConstructorHelpers.h"

AParcialGameMode::AParcialGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
