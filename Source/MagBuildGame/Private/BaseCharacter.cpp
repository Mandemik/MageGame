// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComp");

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComp)
	{
		BaseAttributeSetComp = AbilitySystemComp->GetSet<UBaseAttributeSet>();

		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetHealthAttribute()).AddUObject(this, &ABaseCharacter::OnHealthChangedNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetMaxManaAttribute()).AddUObject(this, &ABaseCharacter::OnManaChangedNative);
		AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSetComp->GetMaxStaminaAttribute()).AddUObject(this, &ABaseCharacter::OnStaminaChangedNative);
	}
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel, int32 inputIndex)
{
	if (AbilitySystemComp)
	{
		if (HasAuthority() && AbilityToGet)
		{
			AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(AbilityToGet, AbilityLevel, inputIndex));
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void ABaseCharacter::GetHealthValues(float& Health, float& MaxHealth)
{
	Health = BaseAttributeSetComp->GetHealth();
	MaxHealth = BaseAttributeSetComp->GetMaxHealth();
}

void ABaseCharacter::SetHealthValues(float NewHealth)
{
	AbilitySystemComp->ApplyModToAttribute(BaseAttributeSetComp->GetHealthAttribute(), EGameplayModOp::Override, NewHealth);
}

void ABaseCharacter::GetManaValues(float& Mana, float& MaxMana)
{
	Mana = BaseAttributeSetComp->GetMana();
	MaxMana = BaseAttributeSetComp->GetMaxMana();
}

void ABaseCharacter::GetStaminaValues(float& Stamina, float& MaxStamina)
{
	Stamina = BaseAttributeSetComp->GetStamina();
	MaxStamina = BaseAttributeSetComp->GetMaxStamina();
}

void ABaseCharacter::OnHealthChangedNative(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnManaChangedNative(const FOnAttributeChangeData& Data)
{
	OnManaChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::OnStaminaChangedNative(const FOnAttributeChangeData& Data)
{
	OnStaminaChanged(Data.OldValue, Data.NewValue);
}

void ABaseCharacter::InitializeAbilityMulti(TArray<TSubclassOf<UGameplayAbility>> AbilityToAcquire, int32 AbilityLevel, int32 inputIndex)
{
	for (TSubclassOf<UGameplayAbility> AbilitItem : AbilityToAcquire)
	{
		InitializeAbility(AbilitItem, AbilityLevel, inputIndex);
	}
}

void ABaseCharacter::RemoveAbilityWithTags(FGameplayTagContainer TagContainer)
{
	TArray<FGameplayAbilitySpec*> MatchingAbilities;
	AbilitySystemComp->GetActivatableGameplayAbilitySpecsByAllMatchingTags(TagContainer, MatchingAbilities, true);
	for (FGameplayAbilitySpec* Spec : MatchingAbilities)
	{
		AbilitySystemComp->ClearAbility(Spec->Handle);
	}
}

void ABaseCharacter::ChangeAbilityLevelWithTags(FGameplayTagContainer TagContainer, int32 NewLevel)
{
	TArray<FGameplayAbilitySpec*> MatchingAbilities;
	AbilitySystemComp->GetActivatableGameplayAbilitySpecsByAllMatchingTags(TagContainer, MatchingAbilities, true);
	for (FGameplayAbilitySpec* Spec : MatchingAbilities)
	{
		Spec->Level = NewLevel;
	}
}

void ABaseCharacter::CancelAbilityWithTags(FGameplayTagContainer WithTags, FGameplayTagContainer WithOut)
{
	AbilitySystemComp->CancelAbilities(&WithTags, &WithOut, nullptr);
}

void ABaseCharacter::AddLooseGameplayTag(FGameplayTag TagToAdd)
{
	GetAbilitySystemComponent()->AddLooseGameplayTag(TagToAdd);
	GetAbilitySystemComponent()->SetTagMapCount(TagToAdd, 1);
}

void ABaseCharacter::RemoveLooseGameplayTag(FGameplayTag TagToRemove)
{
	GetAbilitySystemComponent()->RemoveLooseGameplayTag(TagToRemove);
}

void ABaseCharacter::ApplyGEToTargetData(const FGameplayEffectSpecHandle& GESpace, const FGameplayAbilityTargetDataHandle& TargetData)
{
	for (TSharedPtr<FGameplayAbilityTargetData> Data : TargetData.Data)
	{
		Data->ApplyGameplayEffectSpec(*GESpace.Data.Get());
	}
}
