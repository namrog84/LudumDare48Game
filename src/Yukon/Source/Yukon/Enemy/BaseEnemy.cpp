// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseEnemy.h"

#include "Components/CapsuleComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#include "EnemyBullet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Yukon/Player/MainPlayer.h"
#include "Yukon/Player/MainPlayerState.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    // USceneComponent*
    m_scene = CreateDefaultSubobject<USceneComponent>("m_scene");
    m_scene->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::KeepRelativeTransform);

    m_arrow = CreateDefaultSubobject<UArrowComponent>("m_arrow");
    m_arrow->AttachToComponent(m_scene, FAttachmentTransformRules::KeepRelativeTransform);
    m_sphereComponent = CreateDefaultSubobject<UStaticMeshComponent>("m_sphereComponent");
    m_sphereComponent->AttachToComponent(m_scene, FAttachmentTransformRules::KeepRelativeTransform);
    m_sphereComponent1 = CreateDefaultSubobject<USphereComponent>("m_sphereComponent1");
    m_sphereComponent1->AttachToComponent(m_sphereComponent, FAttachmentTransformRules::KeepRelativeTransform);
    m_sphereComponent2 = CreateDefaultSubobject<USphereComponent>("m_sphereComponent2");
    m_sphereComponent2->AttachToComponent(m_sphereComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
    Super::BeginPlay();
    m_playerChar = Cast<AMainPlayer>(UGameplayStatics::GetActorOfClass(this, AMainPlayer::StaticClass()));
    StartFire();
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (m_playerChar)
    {
        m_goalLoc = m_playerChar->GetActorLocation();

        auto lookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetCapsuleComponent()->GetComponentLocation(), m_goalLoc);
        lookAtRotation.Yaw += 90;
        m_scene->SetWorldRotation(lookAtRotation);

        if (UKismetMathLibrary::Vector_Distance(m_goalLoc, GetActorLocation()) >= m_stopChaseDistance)
        {
            int32 xSign = m_goalLoc.X > GetActorLocation().X ? 1 : -1;
            int32 ySign = m_goalLoc.Y > GetActorLocation().Y ? 1 : -1;
            int32 zSign = m_goalLoc.Z > GetActorLocation().Z ? 1 : -1;
            GetCharacterMovement()->AddForce(FVector(m_force * xSign, m_force * ySign, m_force * zSign));
        }
    }
}

float ABaseEnemy::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    m_enemyHealth -= 1;
    if (m_enemyHealth <= 0)
    {
        UGameplayStatics::PlaySoundAtLocation(this, m_enemyDeathSound, m_sphereComponent->GetComponentLocation());
        UGameplayStatics::SpawnEmitterAtLocation(this, m_asteroidParticleExplosion, GetActorLocation());
        Destroy();
    }
    return Damage;
}

void ABaseEnemy::StartFire()
{
    m_timeLine.SetTimelineLength(0.50);
    FOnTimelineEvent progressFunction{};
    progressFunction.BindDynamic(this, &ABaseEnemy::FireDelegate);
    m_timeLine.AddEvent(0.25, progressFunction);
    m_timeLine.AddEvent(0.50, progressFunction);
}

void ABaseEnemy::FireDelegate()
{
    if (m_playerChar)
    {

        AMainPlayerState* mainPlayerState = Cast<AMainPlayerState>(m_playerChar);
        if (mainPlayerState)
        {
            if (mainPlayerState->m_isAlive)
            {
                auto sphereLoc = m_sphereComponent->GetComponentLocation();
                auto playerLoc = m_playerChar->GetActorLocation();
                if (UKismetMathLibrary::Vector_Distance(sphereLoc, playerLoc) <= m_attackDistance)
                {

                    UGameplayStatics::PlaySoundAtLocation(this, m_enemyFireSound, sphereLoc);
                    GetWorld()->SpawnActor<AEnemyBullet>(AEnemyBullet::StaticClass(), m_sphereComponent1->GetComponentTransform());
                    GetWorld()->SpawnActor<AEnemyBullet>(AEnemyBullet::StaticClass(), m_sphereComponent2->GetComponentTransform());
                }
            }
        }

        // if
        // Cast<m_playerChar->
    }
}
