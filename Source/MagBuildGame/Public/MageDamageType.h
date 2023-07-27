// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "MageDamageType.generated.h"

/**
 * 
 */
UCLASS()
class MAGBUILDGAME_API UMageDamageType : public UDamageType
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		bool CauseHitReaction = false;
	
};
