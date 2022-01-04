// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GOW_Character.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SOMEGODOFWARMECHANIC_API AGOW_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGOW_Character();


	UPROPERTY( VisibleAnywhere,BlueprintReadOnly, Category = "Components")
		USpringArmComponent* SpringarmComponent;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category="Components")
		UCameraComponent* TPCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* LeviathanAxeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Shoot")
		bool bIsShooting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Socket")
		FName WeaponSocketName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	void MoveForward(float value);

	void MoveRight(float value);

	virtual void Jump() override;

	virtual void StopJumping() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sprint")
		float RunSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sprint")
		float WalkSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION()
		void Run();

	UFUNCTION()
		void Walk();

	UFUNCTION()
		void Shoot();

	UFUNCTION()
		void StopShooting();
};
