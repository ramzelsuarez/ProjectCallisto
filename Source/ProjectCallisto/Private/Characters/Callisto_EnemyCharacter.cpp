// Copyright Zel Suarez


#include "Characters/Callisto_EnemyCharacter.h"

#include "AbilitySystem/Callisto_AbilitySystemComponent.h"
#include "AbilitySystem/Callisto_AttributeSet.h"


ACallisto_EnemyCharacter::ACallisto_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	AbilitySystemComponent = CreateDefaultSubobject<UCallisto_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UCallisto_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACallisto_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ACallisto_EnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void ACallisto_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsValid(GetAbilitySystemComponent())) return;
	
	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	
	if (!HasAuthority()) return;
	
	GiveStartupAbilities();
	InitializeAttributes();
}

