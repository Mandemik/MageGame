// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MageGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MAGBUILDGAME_API AMageGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	//Cheat: Block All Damage
	UFUNCTION(Exec, Category = ExecFunction)
		void CheatImmortality(bool enable);

	//Cheat: Gives Player super speed
	UFUNCTION(Exec, Category = ExecFunction)
		void CheatSuperSpeed(bool enable);

	//Cheat: Unlock All Abilites for player
	UFUNCTION(Exec, Category = ExecFunction)
		void CheatUnlockAbility(bool enable);

	//Cheat: Unlock All Abilites for player
	UFUNCTION(Exec, Category = ExecFunction)
		void CheatFinishLevelWithStars(int starnumber);


	UFUNCTION(BlueprintImplementableEvent, Category = "Cheat")
		void BlueprintCheatImmortality(bool enable);

	UFUNCTION(BlueprintImplementableEvent, Category = "Cheat")
		void BlueprintCheatSuperSpeed(bool enable);

	UFUNCTION(BlueprintImplementableEvent, Category = "Cheat")
		void BlueprintCheatUnlockAbility(bool enable);

	UFUNCTION(BlueprintImplementableEvent, Category = "Cheat")
		void BlueprintCheatFinishLevelWithStars(int Starsnumber);
};
