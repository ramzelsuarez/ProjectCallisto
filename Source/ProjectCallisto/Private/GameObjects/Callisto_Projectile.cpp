// Copyright Zel Suarez


#include "GameObjects/Callisto_Projectile.h"

#include "AbilitySystemComponent.h"
#include "Characters/Callisto_PlayerCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameplayTags/CallistoTags.h"
#include "Utils/Callisto_BlueprintLibrary.h"


ACallisto_Projectile::ACallisto_Projectile()
{
	PrimaryActorTick.bCanEverTick = false;
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	
	bReplicates = true;
}

void ACallisto_Projectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	ACallisto_PlayerCharacter* PlayerCharacter = Cast<ACallisto_PlayerCharacter>(OtherActor);
	if (!IsValid(PlayerCharacter)) return;
	if (!PlayerCharacter->IsAlive()) return;
	UAbilitySystemComponent* AbilitySystemComponent = PlayerCharacter->GetAbilitySystemComponent();
	if (!IsValid(AbilitySystemComponent) || !HasAuthority()) return;
	
	FGameplayEventData Payload;
	Payload.Instigator = GetOwner();
	Payload.Target = PlayerCharacter;
	
	UCallisto_BlueprintLibrary::SendDamageEventToPlayer(PlayerCharacter, DamageEffect, Payload, CallistoTags::SetByCaller::Projectile, Damage);
	
	SpawnImpactEffects();
	Destroy();
}


