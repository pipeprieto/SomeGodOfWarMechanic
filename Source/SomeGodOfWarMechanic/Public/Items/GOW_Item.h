// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GOW_Item.generated.h"

class USphereComponent;

UCLASS()
class SOMEGODOFWARMECHANIC_API AGOW_Item : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGOW_Item();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* MainColliderComponent;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PickUp();


	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable, Category="Item")//Funcion que SOLO puede ser llamada en Bluprint y Actúa como evento
	void BP_PickUp();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
