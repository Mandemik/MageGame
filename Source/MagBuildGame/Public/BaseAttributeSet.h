// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class MAGBUILDGAME_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBaseAttributeSet();

	//Attributes for health
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "BaseAttribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
		FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth);


	//Attributes for Mana
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
		FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Mana);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
		FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMana);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
		FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ManaRegeneration);

	//Attributes for Stamina
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
		FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Stamina);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
		FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStamina);

	//Attributes for Armor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
		FGameplayAttributeData PhysicArmor;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, PhysicArmor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseAttribute")
		FGameplayAttributeData MaxPhysicArmor;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxPhysicArmor);

	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

};
