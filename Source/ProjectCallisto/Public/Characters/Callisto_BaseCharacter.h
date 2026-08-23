// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Callisto_BaseCharacter.generated.h"

UCLASS(Abstract)
class PROJECTCALLISTO_API ACallisto_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACallisto_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	void GiveStartupAbilities();

private:
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> StartupAbilities;
};
