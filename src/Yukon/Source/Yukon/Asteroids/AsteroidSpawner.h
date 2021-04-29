// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AsteroidSpawner.generated.h"

UCLASS()
class YUKON_API AAsteroidSpawner : public AActor
{
    GENERATED_BODY()

public:
    AAsteroidSpawner();
    virtual void BeginPlay() override;

    // Component
    UPROPERTY(meta = (DisplayName = "Box"))
    UBoxComponent* m_box = nullptr;

    // properties
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Spawn Count"))
    int32 m_spawnCount = 5;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Scale Min"))
    float m_scaleMin = 1.0f;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Scale Max"))
    float m_scaleMax = 5.0f;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Spawn Class"))
    TSubclassOf<AActor> m_spawnClass = nullptr;

    int32 m_spawned = 0;
};
