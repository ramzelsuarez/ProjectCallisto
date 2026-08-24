// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "Callisto_WidgetComponent.generated.h"


class UAbilitySystemComponent;
class ACallisto_BaseCharacter;
class UCallisto_AbilitySystemComponent;
class UCallisto_AttributeSet;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PROJECTCALLISTO_API UCallisto_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	TMap<FGameplayAttribute, FGameplayAttribute> AttributeMap;
	
private:
	TWeakObjectPtr<ACallisto_BaseCharacter> CallistoCharacter;
	TWeakObjectPtr<UCallisto_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UCallisto_AttributeSet> AttributeSet;
	
	void InitAbilitySystemData();
	bool IsASCInitialized() const;
	void InitializeAttributeDelegate();
	void BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;
	
	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	UFUNCTION()
	void BindToAttributeChanges();
};
