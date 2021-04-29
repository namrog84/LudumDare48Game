// Fill out your copyright notice in the Description page of Project Settings.

#include "AsteroidSpawner.h"

#include "Engine/CollisionProfile.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include <memory>

AAsteroidSpawner::AAsteroidSpawner()
{
    PrimaryActorTick.bCanEverTick = false;

    m_box = CreateDefaultSubobject<UBoxComponent>("m_box");
    SetRootComponent(m_box);
    // m_box->SetRootComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    m_box->SetCollisionProfileName("NoCollision");

    {
        static ConstructorHelpers::FClassFinder<AActor> baseActor(TEXT("/Game/Game/Asteroids/Asteroid"));
        check(baseActor.Succeeded());
        m_spawnClass = baseActor.Class;
    }
}

void AAsteroidSpawner::BeginPlay()
{
    Super::BeginPlay();

    std::shared_ptr<FTimerHandle> timerHandle = std::make_shared<FTimerHandle>();
    std::shared_ptr<FTimerDelegate> callbackHandle = std::make_shared<FTimerDelegate>();

    //FTimerDelegate callback;
    callbackHandle->BindWeakLambda(this, [this, timerHandle, callbackHandle] {
        // do 50 at a time
        for (int32 i = 0; i < 25; i++)
        {
            m_spawned++;
            if(m_spawned >= m_spawnCount)
            {
                //GetWorld()->GetTimerManager().ClearTimer(*timerHandle);
                break;
            }

            FVector location = UKismetMathLibrary::RandomPointInBoundingBox(m_box->GetComponentLocation(), m_box->GetScaledBoxExtent());
            FRotator rotation = FRotator(
                UKismetMathLibrary::RandomFloatInRange(0, 360),
                UKismetMathLibrary::RandomFloatInRange(0, 360),
                UKismetMathLibrary::RandomFloatInRange(0, 360));
            FVector scale = FVector(UKismetMathLibrary::RandomFloatInRange(m_scaleMin, m_scaleMax));

            FTransform spawnTransform(rotation, location, scale);
            // auto pActor = GetWorld()->SpawnActor<AActor>(m_spawnClass, spawnTransform);

            // auto pActor = GetWorld()->SpawnActor<AActor>(m_spawnClass, location, rotation);
            // pActor->SetActorScale3D(scale);

            auto pActor2 = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, m_spawnClass, spawnTransform);
            UGameplayStatics::FinishSpawningActor(pActor2, spawnTransform);
        }
        if(m_spawned <= m_spawnCount)
        {
            GetWorld()->GetTimerManager().SetTimerForNextTick(*callbackHandle);
        }
    });
    // delay replication if multiple changes occur quickly.
    //GetWorld()->GetTimerManager().SetTimer(*timerHandle, callback, 0.02f, true);
    GetWorld()->GetTimerManager().SetTimerForNextTick(*callbackHandle);
}
