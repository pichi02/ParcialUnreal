#include "Character/BatteryCollector.h"

#include "Components/SphereComponent.h"
#include "Pickups/PickUpBase.h"


// Sets default values
ABatteryCollector::ABatteryCollector()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	CollisionSphere->SetupAttachment(RootComponent);
	CollisionSphere->SetSphereRadius(200.0f);
}

// Called when the game starts or when spawned
void ABatteryCollector::BeginPlay()
{
	Super::BeginPlay();
}

void ABatteryCollector::CollectPickups()
{
	
}

// Called every frame
void ABatteryCollector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABatteryCollector::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
