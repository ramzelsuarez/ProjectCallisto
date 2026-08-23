// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/Callisto_GameplayAbility.h"
#include "Callisto_HitReact.generated.h"

UCLASS()
class PROJECTCALLISTO_API UCallisto_HitReact : public UCallisto_GameplayAbility
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable, Category = "Callisto|Abilities")
	void CacheDirectionVectors(AActor* Instigator);
	
	UPROPERTY(BlueprintReadOnly, Category = "Callisto|Abilities")
	FVector AvatarForward;
	
	UPROPERTY(BlueprintReadOnly, Category = "Callisto|Abilities")
	FVector ToInstigator;
};
