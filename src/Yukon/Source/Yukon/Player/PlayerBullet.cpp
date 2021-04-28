// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerBullet.h"

#include "Kismet/KismetMathLibrary.h"
#include "Yukon/Enemy/BaseEnemy.h"
#include "Yukon/Enemy/BigEnemy.h"

// Sets default values
APlayerBullet::APlayerBullet()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerBullet::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APlayerBullet::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APlayerBullet::NotifyHit(
    UPrimitiveComponent* MyComp,
    AActor* Other,
    UPrimitiveComponent* OtherComp,
    bool bSelfMoved,
    FVector HitLocation,
    FVector HitNormal,
    FVector NormalImpulse,
    const FHitResult& Hit)
{
    if (Other)
    {
        if (OtherComp)
        {
            if (Cast<ABaseEnemy>(Other) || Cast<ABigEnemy>(Other))
            {
                Other->TakeDamage(1, FDamageEvent{}, nullptr, nullptr);
            }
            Destroy();
        }
    }
}
