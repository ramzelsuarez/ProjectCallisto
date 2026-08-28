// Copyright Zel Suarez


#include "GameObjects/Callisto_Projectile.h"

#include "AbilitySystemComponent.h"
#include "Characters/Callisto_PlayerCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"


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
	
	FGameplayEffectContextHandle ContextHandle = AbilitySystemComponent->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DamageEffect, 1.f, ContextHandle);
	
	// TODO: Use the Damage variable for the amount of damage to cause
	
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	
	SpawnImpactEffects();
	Destroy();
}


