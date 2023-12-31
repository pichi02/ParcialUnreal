// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ParcialCharacter.generated.h"


UCLASS(config=Game)
class AParcialCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Collision", meta = (AllowPrivateAccess="true"))
	class USphereComponent* CollisionSphere;
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

public:
	AParcialCharacter();

protected:
	UFUNCTION(BlueprintCallable)
	void CollectPickups();
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// To add mapping context
	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

#pragma region POWER LEVEL

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power")
	float basePowerLevel;

	UPROPERTY(VisibleAnywhere, Category="Power")
	float currentPowerLevel;

	UPROPERTY(VisibleAnywhere, Category="Power")
	bool isAlive;

	UPROPERTY(VisibleAnywhere, Category="Power")
	bool win;

public:
	UFUNCTION(BlueprintPure, Category="Power")
	float GetBasePowerLevel();

	UFUNCTION(BlueprintPure, Category="Power")
	float GetCurrentPowerLevel();

	UFUNCTION(BlueprintPure)
	bool GetWin();

	UFUNCTION(BlueprintCallable)
	void SetWin(bool newBool);

	UFUNCTION(BlueprintPure)
	bool GetIsAlive();

	UFUNCTION(BlueprintCallable)
	void UpdateCurrentPowerLevel(float amount);

	UFUNCTION(BlueprintImplementableEvent, Category="Power")
	void OnZeroPower();
#pragma endregion

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	FORCEINLINE class USphereComponent* GetSphereCollision() const { return CollisionSphere; }
};
