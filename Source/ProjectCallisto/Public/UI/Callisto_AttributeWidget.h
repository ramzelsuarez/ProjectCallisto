// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Callisto_AttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "Callisto_AttributeWidget.generated.h"


UCLASS()
class PROJECTCALLISTO_API UCallisto_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Callisto|Attributes")
	FGameplayAttribute Attribute;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Callisto|Attributes")
	FGameplayAttribute MaxAttribute;
	
	void OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, UCallisto_AttributeSet* AttributeSet);
	bool MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;
	
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Attribute Change"))
	void BP_OnAttributeChange(float NewValue, float NewMaxValue);
};
