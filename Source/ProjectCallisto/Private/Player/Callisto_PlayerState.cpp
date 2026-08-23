// Copyright Zel Suarez


#include "Player/Callisto_PlayerState.h"

#include "AbilitySystemComponent.h"

ACallisto_PlayerState::ACallisto_PlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* ACallisto_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
