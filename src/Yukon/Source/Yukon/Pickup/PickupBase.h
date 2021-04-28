// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

UCLASS()
class YUKON_API APickupBase : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupBase();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void Interact(AMainPlayer* mainPlayer, bool param1);
};
