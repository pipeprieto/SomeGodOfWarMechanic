// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GOW_Item.h"
#include "Components/SphereComponent.h"
#include "GOW_Character.h"

// Sets default values
AGOW_Item::AGOW_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainColliderComponent=CreateDefaultSubobject<USphereComponent>(TEXT("MainColliderComponent"));
	MainColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MainColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_WorldDynamic,ECR_Block);
	MainColliderComponent->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	RootComponent = MainColliderComponent;

}

// Called when the game starts or when spawned
void AGOW_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGOW_Item::PickUp()
{
	BP_PickUp();
}


// Called every frame
void AGOW_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGOW_Item::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (IsValid(OtherActor))//Verificando que si sea un actor válido
	{
		AGOW_Character* OverlappedCharacter = Cast<AGOW_Character>(OtherActor);//Guardando el objeto que hace overlap 
		if (IsValid(OverlappedCharacter))//Verificando que sea un objeto de tipo character
		{
			PickUp();
		}
	}
}




