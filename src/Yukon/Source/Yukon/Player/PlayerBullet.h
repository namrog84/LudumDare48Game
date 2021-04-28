// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "PlayerBullet.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class YUKON_API APlayerBullet : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APlayerBullet();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    virtual void NotifyHit(
        UPrimitiveComponent* MyComp,
        AActor* Other,
        UPrimitiveComponent* OtherComp,
        bool bSelfMoved,
        FVector HitLocation,
        FVector HitNormal,
        FVector NormalImpulse,
        const FHitResult& Hit) override;

    // Component
    UPROPERTY()
    USphereComponent* m_collisionComponent = nullptr;

    UPROPERTY()
    UStaticMeshComponent* m_staticMeshCylinderComponent = nullptr;

    UPROPERTY()
    UProjectileMovementComponent* m_projectileComponent = nullptr;
};
