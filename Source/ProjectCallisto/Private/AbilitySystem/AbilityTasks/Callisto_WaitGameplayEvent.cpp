// Copyright Zel Suarez


#include "AbilitySystem/AbilityTasks/Callisto_WaitGameplayEvent.h"

UCallisto_WaitGameplayEvent* UCallisto_WaitGameplayEvent::WaitGameplayEventToActorProxy(AActor* TargetActor,
	FGameplayTag EventTag, bool OnlyTriggerOnce, bool OnlyMatchExact)
{
	UCallisto_WaitGameplayEvent* MyObj = NewObject<UCallisto_WaitGameplayEvent>();
	MyObj->SetAbilityActor(TargetActor);
	MyObj->Tag = EventTag;
	MyObj->OnlyTriggerOnce = OnlyTriggerOnce;
	MyObj->OnlyMatchExact = OnlyMatchExact;
	return MyObj;
}

void UCallisto_WaitGameplayEvent::StartActivation()
{
	Activate();
}
