// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "MainPlayerState.generated.h"

/**
 *
 */
UCLASS()
class YUKON_API AMainPlayerState : public APlayerState
{
    GENERATED_BODY()
public:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
    void AddFuel(int32 fuelAmountToAdd);
    void AddGold(int32 goldToAdd);

    float m_fuel = 0.0f;
    bool m_isAlive = true;
    bool m_isControllable = true;
    float m_shields = 5.0f;
    int32 m_maxGold = 0;

    UPROPERTY()
    USoundBase* m_playerDeathNoise = nullptr;
};
