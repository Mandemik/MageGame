// Fill out your copyright notice in the Description page of Project Settings.
//#include "AbilitySystemComponent.h"
//#include "AbilitySystemInterface.h"
//#include "Abilities/GameplayAbility.h"

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "BaseCharacter.generated.h"

class UBaseAttributeSet;

UCLASS()
class MAGBUILDGAME_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseCharacter")
		UAbilitySystemComponent* AbilitySystemComp;

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel, int32 inputIndex);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;


	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "BaseCharacter")
		const class UBaseAttributeSet* BaseAttributeSetComp;

	UFUNCTION(BlueprintPure,Category = "Base Character")
		void GetHealthValues(float& Health, float& MaxHealth);

	UFUNCTION(BlueprintCallable, Category = "Base Character")
		void SetHealthValues(float NewHealth);

	UFUNCTION(BlueprintPure, Category = "Base Character")
		void GetManaValues(float& Mana, float& MaxMana);

	UFUNCTION(BlueprintPure, Category = "Base Character")
		void GetStaminaValues(float& Stamina, float& MaxStamina);

	void OnHealthChangedNative(const FOnAttributeChangeData& Data);
	void OnManaChangedNative(const FOnAttributeChangeData& Data);
	void OnStaminaChangedNative(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
		void OnHealthChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
		void OnManaChanged(float OldValue, float NewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseCharacter")
		void OnStaminaChanged(float OldValue, float NewValue);


	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void InitializeAbilityMulti(TArray<TSubclassOf<UGameplayAbility>> AbilityToAcquire, int32 AbilityLevel, int32 inputIndex);

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void RemoveAbilityWithTags(FGameplayTagContainer TagContainer);

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void ChangeAbilityLevelWithTags(FGameplayTagContainer TagContainer, int32 NewLevel);

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void CancelAbilityWithTags(FGameplayTagContainer WithTags, FGameplayTagContainer WithOut);

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void AddLooseGameplayTag(FGameplayTag TagToAdd);


	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void RemoveLooseGameplayTag(FGameplayTag TagToRemove);

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		void ApplyGEToTargetData(const FGameplayEffectSpecHandle& GESpace, const FGameplayAbilityTargetDataHandle& TargetData);

		



};
	