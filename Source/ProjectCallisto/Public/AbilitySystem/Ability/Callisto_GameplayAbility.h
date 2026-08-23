// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Callisto_GameplayAbility.generated.h"

UCLASS()
class PROJECTCALLISTO_API UCallisto_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Callisto|Debug")
	bool bDrawDebugs = false;
};
