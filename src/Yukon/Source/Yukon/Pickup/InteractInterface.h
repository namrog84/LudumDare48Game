// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "InteractInterface.generated.h"

class AMainPlayer;

UINTERFACE()
class YUKON_API UInteractableInterface : public UInterface
{
    GENERATED_BODY()
public:
};

class YUKON_API IInteractableInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintImplementableEvent, Category = "Interactable")
    void Interact(AMainPlayer* mainPlayer, bool param1);


    /** Add interface function declarations here */
};
