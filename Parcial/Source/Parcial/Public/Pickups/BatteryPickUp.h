﻿#pragma once

#include "CoreMinimal.h"
#include "PickUpBase.h"
#include "GameFramework/Actor.h"
#include "BatteryPickUp.generated.h"

UCLASS()
class PARCIAL_API ABatteryPickUp : public APickUpBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABatteryPickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power", meta=(BlueprintProtected="true"))
	float chargeAmount;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnPickupCollected_Implementation() override;

	float GetChargeAmount();
};
