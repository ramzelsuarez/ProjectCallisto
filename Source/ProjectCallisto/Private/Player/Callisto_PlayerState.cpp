// Copyright Zel Suarez


#include "Player/Callisto_PlayerState.h"
#include "AbilitySystem/Callisto_AbilitySystemComponent.h"
#include "AbilitySystem/Callisto_AttributeSet.h"

ACallisto_PlayerState::ACallisto_PlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystemComponent = CreateDefaultSubobject<UCallisto_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UCallisto_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACallisto_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
