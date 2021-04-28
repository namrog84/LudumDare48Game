// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class YUKON_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	int32 m_gold = 0;
	bool m_weaponUpgrade = false;
	bool m_shieldUpgrade = false;
};
