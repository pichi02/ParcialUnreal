#include "Pickups/BatteryPickUp.h"


// Sets default values
ABatteryPickUp::ABatteryPickUp()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PickUpMesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ABatteryPickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABatteryPickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
