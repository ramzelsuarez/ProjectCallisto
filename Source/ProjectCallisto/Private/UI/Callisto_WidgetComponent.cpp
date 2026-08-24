// Copyright Zel Suarez


#include "UI/Callisto_WidgetComponent.h"

#include "AbilitySystem/Callisto_AbilitySystemComponent.h"
#include "AbilitySystem/Callisto_AttributeSet.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/Callisto_BaseCharacter.h"
#include "UI/Callisto_AttributeWidget.h"


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
	for (const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair : AttributeMap)
	{
		BindWidgetToAttributeChanges(GetUserWidgetObject(), Pair); // For checking the owned widget object.
		
		GetUserWidgetObject()->WidgetTree->ForEachWidget([this, &Pair](UWidget* ChildWidget)
		{
			BindWidgetToAttributeChanges(ChildWidget, Pair);
		});
	}
}

void UCallisto_WidgetComponent::BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	UCallisto_AttributeWidget* AttributeWidget = Cast<UCallisto_AttributeWidget>(WidgetObject);
	if (!IsValid(AttributeWidget)) return; // We only care about Callisto Widgets
	if (!AttributeWidget->MatchesAttributes(Pair)) return; // Only subscribe for matching Attributes
		
	AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // for initial values.
		
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Key).AddLambda([this, AttributeWidget, &Pair](const FOnAttributeChangeData& AttributeChangeData)
	{
		AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // For changes during the game
	});
}