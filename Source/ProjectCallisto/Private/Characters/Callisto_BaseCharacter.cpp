// Copyright Zel Suarez


#include "ProjectCallisto/Public/Characters/Callisto_BaseCharacter.h"

#include "Components/SkeletalMeshComponent.h"


ACallisto_BaseCharacter::ACallisto_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	// Tick and refresh bone transforms whether rendered or not - for bone updates on a dedicated server
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	
}

UAbilitySystemComponent* ACallisto_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

