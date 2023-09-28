#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BatteryCollector.generated.h"

UCLASS()
class PARCIAL_API ABatteryCollector : public ACharacter
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Collision", meta = (AllowPrivateAccess="true"))
	class USphereComponent* CollisionSphere;

public:
	// Sets default values for this character's properties
	ABatteryCollector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void CollectPickups();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE class USphereComponent* GetSphereCollision() const { return CollisionSphere; }
};