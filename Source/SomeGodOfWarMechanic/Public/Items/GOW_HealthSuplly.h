// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/GOW_Item.h"
#include "GOW_HealthSuplly.generated.h"


class UStaticMeshComponent;

UCLASS()
class SOMEGODOFWARMECHANIC_API AGOW_HealthSuplly : public AGOW_Item
{
	GENERATED_BODY()



public:
	AGOW_HealthSuplly();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* CapsuleMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* SphereMeshComponent;


protected:
	UFUNCTION(BlueprintCallable, Category = "HealthSupply")
		void AddHealth();


};
