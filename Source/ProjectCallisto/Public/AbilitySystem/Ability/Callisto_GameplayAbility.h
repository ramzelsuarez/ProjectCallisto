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
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Callisto|Debug")
	bool bDrawDebugs = false;
};
