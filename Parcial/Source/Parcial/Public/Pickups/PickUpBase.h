// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpBase.generated.h"

UCLASS()
class PARCIAL_API APickUpBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickUpBase();

	UFUNCTION(BlueprintPure, Category="Pickup")
	bool GetIsActive() const;

	UFUNCTION(BlueprintCallable, Category="Pickup")
	void SetIsActive(bool newBool);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool isActive;

#pragma region COMPONENTS

	UPROPERTY(VisibleAnywhere, Category="Components")

	UStaticMeshComponent* PickUpMesh;
#pragma  endregion

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
