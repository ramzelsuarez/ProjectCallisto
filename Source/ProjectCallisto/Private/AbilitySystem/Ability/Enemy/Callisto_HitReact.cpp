// Copyright Zel Suarez


#include "AbilitySystem/Ability/Enemy/Callisto_HitReact.h"

void UCallisto_HitReact::CacheDirectionVectors(AActor* Instigator)
{
	AvatarForward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	
	const FVector AvatarLocation = GetAvatarActorFromActorInfo()->GetActorLocation();
	const FVector InstigatorLocation = Instigator->GetActorLocation();
	
	ToInstigator = InstigatorLocation - AvatarLocation;
	ToInstigator.Normalize();
}
