// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Character.h"

#include "BaseEnemy.generated.h"

class AMainPlayer;
UCLASS()
class YUKON_API ABaseEnemy : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    ABaseEnemy();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

    void StartFire();
    void FireDelegate();

    // Components
    UPROPERTY()
    USceneComponent* m_scene = nullptr;
    UPROPERTY()
    UArrowComponent* m_arrow = nullptr;
    UPROPERTY()
    UStaticMeshComponent* m_sphereComponent = nullptr;
    UPROPERTY()
    USphereComponent* m_sphereComponent1 = nullptr;
    UPROPERTY()
    USphereComponent* m_sphereComponent2 = nullptr;

    FTimeline m_timeLine;

    // Properties
    int32 m_enemyHealth = 5;
    int32 m_totalHealth = 0;
    FVector m_goalLoc;
    float m_attackDistance = 8000;
    float m_stopChaseDistance = 2500;
    float m_force = 60000.0f;

    AMainPlayer* m_playerChar = nullptr;

    // Assets
    UPROPERTY()
    USoundBase* m_enemyDeathSound = nullptr;
    UPROPERTY()
    UParticleSystem* m_asteroidParticleExplosion= nullptr;
    UPROPERTY()
    USoundBase* m_enemyFireSound = nullptr;
};
