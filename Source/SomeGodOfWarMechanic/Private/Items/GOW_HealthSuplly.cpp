// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GOW_HealthSuplly.h"
#include "Components/StaticMeshComponent.h"


AGOW_HealthSuplly::AGOW_HealthSuplly() 
{
	CapsuleMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CapsuleMeshComponent"));
	CapsuleMeshComponent->SetupAttachment(RootComponent);

	SphereMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMeshComponent"));
	SphereMeshComponent->SetupAttachment(CapsuleMeshComponent);
}

void AGOW_HealthSuplly::AddHealth()
{
}
