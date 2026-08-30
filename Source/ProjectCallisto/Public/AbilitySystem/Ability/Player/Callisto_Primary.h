// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/Callisto_GameplayAbility.h"
#include "Callisto_Primary.generated.h"

UCLASS()
class PROJECTCALLISTO_API UCallisto_Primary : public UCallisto_GameplayAbility
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable, Category = "Callisto|Abilities")
	void SendHitReactEventToActors(const TArray<AActor*>& ActorsHit);
	
protected:
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Callisto|Abilities")
    	float HitBoxRadius = 100.0f;
    	
    	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Callisto|Abilities")
    	float HitBoxForwardOffset = 200.0f;
    	
    	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Callisto|Abilities")
    	float HitBoxElevationOffset = 20.0f;
};
