// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AbilitySystem/Ability/Callisto_GameplayAbility.h"
#include "Callisto_SearchForTarget.generated.h"

namespace EPathFollowingResult
{
	enum Type : int;
}

class UAITask_MoveTo;
class ACallisto_BaseCharacter;
class UAbilityTask_WaitDelay;
class ACallisto_EnemyCharacter;
class AAIController;
class UCallisto_WaitGameplayEvent;


UCLASS()
class PROJECTCALLISTO_API UCallisto_SearchForTarget : public UCallisto_GameplayAbility
{
	GENERATED_BODY()
public:
	UCallisto_SearchForTarget();
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	TWeakObjectPtr<ACallisto_EnemyCharacter> OwningEnemy;
	TWeakObjectPtr<AAIController> OwningAIController;
	TWeakObjectPtr<ACallisto_BaseCharacter> TargetBaseCharacter;
	
	
private:
	
	UPROPERTY()
	TObjectPtr<UCallisto_WaitGameplayEvent> WaitGameplayEventTask;
	
	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> SearchDelayTask;
	
	UPROPERTY()
	TObjectPtr<UAITask_MoveTo> MoveToLocationOrActorTask;
	
	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> AttackDelayTask;
	
	void StartSearch();
	
	UFUNCTION()
	void EndAttackEventReceived(FGameplayEventData Payload);
	
	UFUNCTION()
	void Search();
	
	void MoveToTargetAndAttack();
	
	UFUNCTION()
	void AttackTarget(TEnumAsByte<EPathFollowingResult::Type> Result, AAIController* AIController);
	
	UFUNCTION()
	void Attack();
};
