// Copyright Zel Suarez


#include "UI/Callisto_WidgetComponent.h"

#include "AbilitySystem/Callisto_AbilitySystemComponent.h"
#include "AbilitySystem/Callisto_AttributeSet.h"
#include "Characters/Callisto_BaseCharacter.h"


void UCallisto_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilitySystemData();
	
	if (!IsASCInitialized())
	{
		CallistoCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
		return;
	}
	
	InitializeAttributeDelegate();
}

void UCallisto_WidgetComponent::InitAbilitySystemData()
{
	CallistoCharacter = Cast<ACallisto_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UCallisto_AttributeSet>(CallistoCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UCallisto_AbilitySystemComponent>(CallistoCharacter->GetAbilitySystemComponent());
}

bool UCallisto_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UCallisto_WidgetComponent::InitializeAttributeDelegate()
{
	if (!AttributeSet->bAttributesInitialized)
	{
		AttributeSet->OnAttributesInitialized.AddDynamic(this, &ThisClass::BindToAttributeChanges);
	}
	else
	{
		BindToAttributeChanges();
	}
}

void UCallisto_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UCallisto_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UCallisto_AttributeSet>(AS);
	
	if (!IsASCInitialized()) return;
	InitializeAttributeDelegate();
}

void UCallisto_WidgetComponent::BindToAttributeChanges()
{
	// TODO: Listen for changes to Gameplay Attributes and update widgets accordingly.
}

