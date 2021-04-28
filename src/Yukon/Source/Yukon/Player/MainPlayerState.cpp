// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerState.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Yukon/Asteroids/GoldAsteroid.h"
#include "Yukon/MainGameInstance.h"

void AMainPlayerState::BeginPlay()
{
    TArray<AActor*> outActors;
    UGameplayStatics::GetAllActorsOfClass(this, AGoldAsteroid::StaticClass(), outActors);
    m_maxGold = outActors.Num();

    UMainGameInstance* mainGameInstance = Cast<UMainGameInstance>(GetGameInstance());
    if (mainGameInstance)
    {
        if (mainGameInstance->m_shieldUpgrade)
        {
            m_shields = 10;
        }
    }
}

float AMainPlayerState::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    if (m_isControllable && m_isAlive)
    {
        m_shields = UKismetMathLibrary::Clamp(Damage, 0, Damage - m_shields);
        if (m_shields <= 0)
        {
            m_isAlive = false;
            // UE_LOG(LogTemp, Warning, TEXT("You died"));
            UKismetSystemLibrary::PrintString(this, "You Died!");
            m_isControllable = false;
            
            UGameplayStatics::PlaySoundAtLocation(this, m_playerDeathNoise, RootComponent->GetComponentLocation());
        }
    }
    return Damage;
}

void AMainPlayerState::AddFuel(int32 fuelAmountToAdd)
{
    m_fuel += fuelAmountToAdd;
}

void AMainPlayerState::AddGold(int32 goldToAdd)
{
    UMainGameInstance* mainGame = Cast<UMainGameInstance>(GetGameInstance());
    if (mainGame)
    {
        mainGame->m_gold = mainGame->m_gold + goldToAdd;
        m_maxGold--;
    }
}
