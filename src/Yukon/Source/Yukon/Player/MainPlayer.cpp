// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayer.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    InputComponent->BindAction("Jump", IE_Pressed, this, &AMainPlayer::CustomJump);
    InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AMainPlayer::Escape);
    InputComponent->BindAxis("TurnRate", this, &AMainPlayer::TurnRate);
    InputComponent->BindAxis("LookUpRate", this, &AMainPlayer::LookUpRate);
    InputComponent->BindAxis("MoveForward", this, &AMainPlayer::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &AMainPlayer::MoveRight);
}

void AMainPlayer::NotifyActorBeginOverlap(AActor* otherActor)
{
    // interact
    // weaponShopUpgrade
    // ShieldShopUpgrade
}

void AMainPlayer::CustomJump() {}

void AMainPlayer::TurnRate(float axisValue)
{
    AddControllerYawInput(UGameplayStatics::GetWorldDeltaSeconds(this) * m_baseTurnRate * axisValue);
}

void AMainPlayer::LookUpRate(float axisValue)
{
    AddControllerPitchInput(UGameplayStatics::GetWorldDeltaSeconds(this) * m_baseLookUpRate * axisValue);
}

void AMainPlayer::MoveForward(float axisValue)
{
    AddMovementInput(m_firstPersonCamera->GetForwardVector(), axisValue);
}

void AMainPlayer::MoveRight(float axisValue)
{
    AddMovementInput(m_firstPersonCamera->GetRightVector(), axisValue);
}

void AMainPlayer::Escape()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}
