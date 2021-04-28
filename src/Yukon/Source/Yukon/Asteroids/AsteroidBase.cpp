// Fill out your copyright notice in the Description page of Project Settings.

#include "AsteroidBase.h"

#include "Kismet/GameplayStatics.h"
#include "Yukon/Player/PlayerBullet.h"

// Sets default values
AAsteroidBase::AAsteroidBase()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAsteroidBase::BeginPlay()
{
    Super::BeginPlay();
}

void AAsteroidBase::NotifyHit(
    UPrimitiveComponent* MyComp,
    AActor* Other,
    UPrimitiveComponent* OtherComp,
    bool bSelfMoved,
    FVector HitLocation,
    FVector HitNormal,
    FVector NormalImpulse,
    const FHitResult& Hit)
{
    if (Other->GetClass()->IsChildOf<APlayerBullet>())
    {
        m_health--;
        if (m_health <= 0)
        {
            check(m_asteroidExplodeSound);
            UGameplayStatics::PlaySoundAtLocation(this, m_asteroidExplodeSound, GetActorLocation(), FRotator::ZeroRotator);

            check(m_asteroidExplosionParticles);
            UGameplayStatics::SpawnEmitterAtLocation(
                this, m_asteroidExplosionParticles, GetActorLocation(), GetActorRotation(), GetActorScale3D());
            Destroy();
        }
        else
        {
            UGameplayStatics::PlaySoundAtLocation(this, m_asteroidHitSound, GetActorLocation(), FRotator::ZeroRotator);
        }
    }
}

// Called every frame
void AAsteroidBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
