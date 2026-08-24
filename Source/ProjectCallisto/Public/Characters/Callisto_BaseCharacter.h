// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Callisto_BaseCharacter.generated.h"

class UAttributeSet;
class UGameplayAbility;
class UGameplayEffect;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FASCInitialized, UAbilitySystemComponent*, ASC, UAttributeSet*, AS);

UCLASS(Abstract)
class PROJECTCALLISTO_API ACallisto_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACallisto_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const { return nullptr;};
	
	UPROPERTY(BlueprintAssignable)
	FASCInitialized OnASCInitialized;
protected:
	void GiveStartupAbilities();
	void InitializeAttributes() const;
private:
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> StartupAbilities;
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Effects")
	TSubclassOf<UGameplayEffect> InitializeAttributesEffect;
};
