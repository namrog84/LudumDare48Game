// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupBase.h"

#include "Internationalization/Internationalization.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetTextLibrary.h"

#define LOCTEXT_NAMESPACE "APickupBase"

// Sets default values
APickupBase::APickupBase()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APickupBase::Interact(AMainPlayer* mainPlayer, bool param1)
{
    auto name = UKismetTextLibrary::Conv_StringToText(UKismetSystemLibrary::GetDisplayName(this));
    auto text = FText::Format(LOCTEXT("ExampleFText", "Unimplemented Pickup Item: {0}."), name);
    UKismetSystemLibrary::PrintText(this, text);
}
