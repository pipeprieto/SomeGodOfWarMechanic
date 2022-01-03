// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GOW_Character.h"

// Sets default values
AGOW_Character::AGOW_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringarmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringarmComponent"));
	SpringarmComponent->bUsePawnControlRotation = true;
	SpringarmComponent->SetupAttachment(RootComponent);


	TPCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TP_CameraComponent"));
	TPCameraComponent->SetupAttachment(SpringarmComponent);

	RunSpeed = 1000.0f;
	WalkSpeed = 600.0f;


}

// Called when the game starts or when spawned
void AGOW_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGOW_Character::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void AGOW_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void AGOW_Character::Jump()
{
	Super::Jump();
}

void AGOW_Character::StopJumping()
{
	Super::StopJumping();
}


// Called every frame
void AGOW_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGOW_Character::Run()
{
	GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void AGOW_Character::Walk()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}



// Called to bind functionality to input
void AGOW_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Character Movement
	PlayerInputComponent->BindAxis("Forward", this, &AGOW_Character::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &AGOW_Character::MoveRight);

	//Mouselook
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacter::AddControllerYawInput);

	//Jump
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AGOW_Character::Jump);
	PlayerInputComponent->BindAction("Jump",IE_Released, this, &AGOW_Character::StopJumping);

	//Sprint
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AGOW_Character::Run);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AGOW_Character::Walk);


}



