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
	float GetPowerToWIn() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float delayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float decayAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float powerToWin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float powerToWinMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	TSubclassOf<UUserWidget> mainHUDClass;

	UPROPERTY()
	class UUserWidget* activeWidget;
	virtual void BeginPlay() override;

	void StartPowerLevelDecay();
};
