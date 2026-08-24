// Copyright Zel Suarez


#include "Player/Callisto_PlayerState.h"
#include "AbilitySystem/Callisto_AbilitySystemComponent.h"

ACallisto_PlayerState::ACallisto_PlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystemComponent = CreateDefaultSubobject<UCallisto_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ACallisto_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
