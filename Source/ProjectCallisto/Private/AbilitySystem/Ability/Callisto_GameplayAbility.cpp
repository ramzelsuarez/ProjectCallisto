// Copyright Zel Suarez


#include "AbilitySystem/Ability/Callisto_GameplayAbility.h"

#include "Engine/Engine.h"

void UCallisto_GameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                                const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                                const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	if (bDrawDebugs && IsValid(GEngine))
	{
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Cyan, FString::Printf(TEXT("%s Activated"), *GetName()));
	}
}
