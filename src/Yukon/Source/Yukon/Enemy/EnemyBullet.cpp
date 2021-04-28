// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyBullet.h"

#include "BaseEnemy.h"
#include "BigEnemy.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AEnemyBullet::AEnemyBullet()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    m_collisionComponent = CreateDefaultSubobject<USphereComponent>("m_collisionComponent");
    SetRootComponent(m_collisionComponent);
    m_sphereComponent = CreateDefaultSubobject<UStaticMeshComponent>("m_sphereComponent");
    m_sphereComponent->AttachToComponent(m_collisionComponent, FAttachmentTransformRules::KeepRelativeTransform);
    m_cylinderComponent = CreateDefaultSubobject<UStaticMeshComponent>("m_cylinderComponent");
    m_cylinderComponent->AttachToComponent(m_collisionComponent, FAttachmentTransformRules::KeepRelativeTransform);
    m_coneComponent = CreateDefaultSubobject<UStaticMeshComponent>("m_coneComponent");
    m_coneComponent->AttachToComponent(m_collisionComponent, FAttachmentTransformRules::KeepRelativeTransform);

    m_projectile = CreateDefaultSubobject<UProjectileMovementComponent>("m_projectile");
    // m_projectile->Set
}

// Called when the game starts or when spawned
void AEnemyBullet::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AEnemyBullet::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AEnemyBullet::NotifyHit(
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
        if (OtherComp->IsCollisionEnabled())
        {
            if (Cast<ABaseEnemy>(Other) || Cast<ABigEnemy>(Other))
            {
                Other->TakeDamage(1, FDamageEvent{}, nullptr, nullptr);
            }
            Destroy();
        }
    }
}
