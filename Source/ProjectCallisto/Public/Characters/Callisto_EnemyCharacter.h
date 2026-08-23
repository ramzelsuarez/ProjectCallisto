// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "Callisto_BaseCharacter.h"
#include "Callisto_EnemyCharacter.generated.h"

class UAbilitySystemComponent;

UCLASS()
class PROJECTCALLISTO_API ACallisto_EnemyCharacter : public ACallisto_BaseCharacter
{
	GENERATED_BODY()

public:
	ACallisto_EnemyCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
