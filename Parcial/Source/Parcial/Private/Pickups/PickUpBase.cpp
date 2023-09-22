// Fill out your copyright notice in the Description page of Project Settings.


#include "Parcial/Public/Pickups/PickUpBase.h"


// Sets default values
APickUpBase::APickUpBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isActive = true;
	PickUpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	RootComponent = PickUpMesh;
}

bool APickUpBase::GetIsActive()const
{
	return isActive;
}

void APickUpBase::SetIsActive(bool newBool) 
{
	isActive = newBool;
}

// Called when the game starts or when spawned
void APickUpBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APickUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
