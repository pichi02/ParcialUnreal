// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ParcialGameMode.generated.h"

UCLASS(minimalapi)
class AParcialGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AParcialGameMode();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float delayTime;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float decayAmount;

	virtual void BeginPlay() override;

	void StartPowerLevelDecay();
};
