// Copyright Zel Suarez


#include "Utils/Callisto_BlueprintLibrary.h"

#include "AbilitySystem/Callisto_AttributeSet.h"
#include "Characters/Callisto_BaseCharacter.h"
#include "GameplayTags/CallistoTags.h"
#include "Kismet/GameplayStatics.h"

EHitDirection UCallisto_BlueprintLibrary::GetHitDirection(const FVector& TargetForward, const FVector& ToInstigator)
{
	const float Dot = FVector::DotProduct(TargetForward, ToInstigator);
	if (Dot < -0.5f)
	{
		return EHitDirection::Back;
	}
	if (Dot < 0.5f)
	{
		// Either left or right
		const FVector Cross = FVector::CrossProduct(TargetForward, ToInstigator);
		if (Cross.Z < 0.f)
		{
			return EHitDirection::Left;
		}
		return EHitDirection::Right;
	}
	return EHitDirection::Forward;
}

FName UCallisto_BlueprintLibrary::GetHitDirectionName(const EHitDirection& HitDirection)
{
	switch (HitDirection)
	{
		case EHitDirection::Left: return FName("Left");
		case EHitDirection::Right: return FName("Right");
		case EHitDirection::Forward: return FName("Forward");
		case EHitDirection::Back: return FName("Back");
		default: return FName("None");
	}
}

FClosestActorWithTagResult UCallisto_BlueprintLibrary::FindClosestActorWithTag(const UObject* WorldContextObject, const FVector& Origin, const FName& Tag)
{
	TArray<AActor*> ActorsWithTag;
	UGameplayStatics::GetAllActorsWithTag(WorldContextObject, Tag, ActorsWithTag);
	
	float ClosestDistance = TNumericLimits<float>::Max();
	AActor* ClosestActor = nullptr;
	
	for (AActor* Actor : ActorsWithTag)
	{
		if (!IsValid(Actor)) continue;
		ACallisto_BaseCharacter* BaseCharacter = Cast<ACallisto_BaseCharacter>(Actor);
		if (!IsValid(BaseCharacter) || !BaseCharacter->IsAlive()) continue;
		
		const float Distance = FVector::Dist(Origin, Actor->GetActorLocation());
		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			ClosestActor = Actor;
		}
	}
	
	FClosestActorWithTagResult Result;
	Result.Actor = ClosestActor;
	Result.Distance = ClosestDistance;
	
	return Result;
}

void UCallisto_BlueprintLibrary::SendDamageEventToPlayer(AActor* Target,
	const TSubclassOf<UGameplayEffect>& DamageEffect, const FGameplayEventData& Payload, const FGameplayTag& DataTag,
	float Damage)
{
	ACallisto_BaseCharacter* PlayerCharacter = Cast<ACallisto_BaseCharacter>(Target);
	if (!IsValid(PlayerCharacter)) return;
	if (!PlayerCharacter->IsAlive()) return;
	
	UCallisto_AttributeSet* AttributeSet = Cast<UCallisto_AttributeSet>(PlayerCharacter->GetAttributeSet());
	if (!IsValid(AttributeSet)) return;
	
	const bool bLethal = AttributeSet->GetHealth() - Damage <= 0.f;
	const FGameplayTag EventTag = bLethal ? CallistoTags::Events::Player::Death : CallistoTags::Events::Player::HitReact;
	
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(PlayerCharacter, EventTag, Payload);
	
	UAbilitySystemComponent* TargetASC = PlayerCharacter->GetAbilitySystemComponent();
	if (!IsValid(TargetASC)) return;
	
	FGameplayEffectContextHandle ContextHandle = TargetASC->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(DamageEffect, 1.f, ContextHandle);
	
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, DataTag, -Damage);
	
	TargetASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}
