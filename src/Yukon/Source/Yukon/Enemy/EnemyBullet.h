// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "EnemyBullet.generated.h"

UCLASS()
class YUKON_API AEnemyBullet : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AEnemyBullet();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
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

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USphereComponent* m_collisionComponent = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* m_cylinderComponent = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* m_sphereComponent = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UStaticMeshComponent* m_coneComponent = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UProjectileMovementComponent* m_projectile = nullptr;
};
