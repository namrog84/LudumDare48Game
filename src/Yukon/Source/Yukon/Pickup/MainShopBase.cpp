// Fill out your copyright notice in the Description page of Project Settings.


#include "MainShopBase.h"

// Sets default values
AMainShopBase::AMainShopBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainShopBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainShopBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

