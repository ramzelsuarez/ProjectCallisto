// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "Callisto_PlayerState.generated.h"

class UAbilitySystemComponent;

UCLASS()
class PROJECTCALLISTO_API ACallisto_PlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	ACallisto_PlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
private:
	
	UPROPERTY(VisibleAnywhere, Category = "Callisto|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
