// Copyright Zel Suarez


#include "Notifies/Callisto_MeleeAttack.h"

#include "AbilitySystemComponent.h"
#include "BoneProxy.h"
#include "KismetTraceUtils.h"
#include "SAnimNotifyShared.h"
#include "Characters/Callisto_PlayerCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/Engine.h"
#include "GameplayTags/CallistoTags.h"
#include "Kismet/KismetMathLibrary.h"

void UCallisto_MeleeAttack::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                       float FromDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FromDeltaTime, EventReference);
	
	if (!IsValid(MeshComp)) return;
	if (!IsValid(MeshComp->GetOwner())) return;
	
	TArray<FHitResult> Hits = PerformSphereTrace(MeshComp);
	SendEventsToActors(MeshComp, Hits);
}

TArray<FHitResult> UCallisto_MeleeAttack::PerformSphereTrace(USkeletalMeshComponent* MeshComp) const
{
	TArray<FHitResult> OutHits;
	
	const FTransform SocketTransform = MeshComp->GetSocketTransform(SocketName);
	const FVector Start = SocketTransform.GetLocation();
	const FVector ExtendedSocketDirection = UKismetMathLibrary::GetForwardVector(SocketTransform.GetRotation().Rotator()) * SocketExtensionOffset;
	const FVector End = Start - ExtendedSocketDirection;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(MeshComp->GetOwner());
	FCollisionResponseParams ResponseParams;
	ResponseParams.CollisionResponse.SetAllChannels(ECR_Ignore);
	ResponseParams.CollisionResponse.SetResponse(ECC_Pawn, ECR_Block);
	UWorld* World = GEngine->GetWorldFromContextObject(MeshComp, EGetWorldErrorMode::LogAndReturnNull);
	if (!IsValid(World)) return OutHits;
	
	bool const bHit = World->SweepMultiByChannel(
		OutHits, 
		Start, 
		End, 
		FQuat::Identity,
		ECC_Visibility, 
		FCollisionShape::MakeSphere(SphereTraceRadius), 
		Params, 
		ResponseParams);
	
	if (bDrawDebugs)
	{
		DrawDebugSphereTraceMulti(
			World, 
			Start, 
			End, 
			SphereTraceRadius, 
			EDrawDebugTrace::ForDuration, 
			bHit, 
			OutHits, 
			FColor::Red, 
			FColor::Green, 
			5.f);
	}
	
	return OutHits;
}

void UCallisto_MeleeAttack::SendEventsToActors(USkeletalMeshComponent* MeshComp, const TArray<FHitResult>& Hits) const
{
	for (const FHitResult& Hit : Hits)
	{
		ACallisto_PlayerCharacter* PlayerCharacter = Cast<ACallisto_PlayerCharacter>(Hit.GetActor());
		if (!IsValid(PlayerCharacter)) continue;
		if (!PlayerCharacter->IsAlive()) continue;
		UAbilitySystemComponent* ASC = PlayerCharacter->GetAbilitySystemComponent();
		if (!IsValid(ASC)) continue;
		
		FGameplayEffectContextHandle ContextHandle = ASC->MakeEffectContext();
		ContextHandle.AddHitResult(Hit);
		
		FGameplayEventData Payload;
		Payload.Target = PlayerCharacter;
		Payload.ContextHandle = ContextHandle;
		Payload.Instigator = MeshComp->GetOwner();
		
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(MeshComp->GetOwner(), CallistoTags::Events::Enemy::MeleeTraceHit, Payload);
	}
}
