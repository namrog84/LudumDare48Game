// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Yukon/MainGameInstance.h"

#include "MainPlayer.generated.h"

UCLASS()
class YUKON_API AMainPlayer : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AMainPlayer();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual void NotifyActorBeginOverlap(AActor* otherActor) override;


    void CustomJump();
    void TurnRate(float axisValue);
    void LookUpRate(float axisValue);
    void MoveForward(float axisValue);
    void MoveRight(float axisValue);
    void Escape();

    FVector m_GunOffset = FVector(100.0f, 0.0f, -10.0f);
    float m_baseTurnRate;
    float m_baseLookUpRate = 45;
    TArray<FName> m_levelNames;
    bool m_atWeaponShop = false;
    bool m_atShieldShop = false;
    UMainGameInstance* m_gameInstance = nullptr;

    float m_costToUpgrade = 10;
    float m_currentCannon = 0;

    // todo
    AActor* m_asWeaponShopUpgrade = nullptr;
    AActor* m_asShieldShopUpgrade = nullptr;


    UCameraComponent* m_firstPersonCamera = nullptr;
}; 


