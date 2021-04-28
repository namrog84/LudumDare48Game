// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AsteroidBase.generated.h"

class UCapsuleComponent;

UCLASS()
class YUKON_API AAsteroidBase : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AAsteroidBase();

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

    // Components
    UPROPERTY()
    UStaticMesh* m_staticMesh = nullptr;
    UPROPERTY()
    UCapsuleComponent* m_capsuleComponent = nullptr;

    // Properties
    UPROPERTY()
    int32 m_health = 2;
    UPROPERTY()
    bool m_isPendingDestroy = false;
    UPROPERTY()
    USoundBase* m_asteroidExplodeSound = nullptr;
    UPROPERTY()
    USoundBase* m_asteroidHitSound = nullptr;
    UPROPERTY()
    UParticleSystem* m_asteroidExplosionParticles = nullptr;

};
