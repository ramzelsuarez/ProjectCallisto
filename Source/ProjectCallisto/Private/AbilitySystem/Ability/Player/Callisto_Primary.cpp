// Copyright Zel Suarez


#include "AbilitySystem/Ability/Player/Callisto_Primary.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Engine/World.h"
#include "GameplayTags/CallistoTags.h"

void UCallisto_Primary::SendHitReactEventToActors(const TArray<AActor*>& ActorsHit)
{
	for (AActor* HitActor : ActorsHit)
	{
		FGameplayEventData PayLoad;
		PayLoad.Instigator = GetAvatarActorFromActorInfo();
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitActor, CallistoTags::Events::Enemy::HitReact, PayLoad);
	}
}
