// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Callisto_Projectile.generated.h"

class UGameplayEffect;
class UProjectileMovementComponent;

UCLASS()
class PROJECTCALLISTO_API ACallisto_Projectile : public AActor
{
	GENERATED_BODY()

public:
	ACallisto_Projectile();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Callisto|Damage", meta = (ExposeOnSpawn, ClampMin = "0.0"))
	float Damage{-25.f};
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Callisto|Projectile")
	void SpawnImpactEffects();
	
private:
	
	UPROPERTY(VisibleAnywhere, Category = "Callisto|Projectile")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Damage")
	TSubclassOf<UGameplayEffect> DamageEffect;
};
