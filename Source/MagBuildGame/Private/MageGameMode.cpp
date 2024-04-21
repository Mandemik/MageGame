// Fill out your copyright notice in the Description page of Project Settings.


#include "MageGameMode.h"

void AMageGameMode::CheatImmortality(bool enable)
{
	BlueprintCheatImmortality(enable);
}

void AMageGameMode::CheatSuperSpeed(bool enable)
{
	BlueprintCheatSuperSpeed(enable);
}

void AMageGameMode::CheatUnlockAbility(bool enable)
{
	BlueprintCheatUnlockAbility(enable);
}

void AMageGameMode::CheatFinishLevelWithStars(int starnumber)
{
	BlueprintCheatFinishLevelWithStars(starnumber);
}

void AMageGameMode::CheatKillAllAi(bool enable)
{
	BlueprintCheatKillAllAi(enable);
}

