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
	}
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

void UCallisto_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UCallisto_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UCallisto_AttributeSet>(AS);
	
	// TODO: Check if the Attribute Set has been initialized with the first Gameplay Effect
	// If not, bind to some delegate that will be broadcast when it is initialized.
}

