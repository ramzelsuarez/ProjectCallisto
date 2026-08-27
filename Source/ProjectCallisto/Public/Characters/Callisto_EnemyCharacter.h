// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "Callisto_BaseCharacter.h"
#include "Callisto_EnemyCharacter.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class PROJECTCALLISTO_API ACallisto_EnemyCharacter : public ACallisto_BaseCharacter
{
	GENERATED_BODY()

public:
	ACallisto_EnemyCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Callisto|AI")
	float AcceptanceRadius{500.f};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Callisto|AI")
	float MinAttackDelay{.1f};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Callisto|AI")
	float MaxAttackDelay{.5f};

protected:
	virtual void BeginPlay() override;
	
private:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
