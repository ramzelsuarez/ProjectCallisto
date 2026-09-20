// Copyright Zel Suarez

#include "Notifies/Callisto_MeleeAttack.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Characters/Callisto_PlayerCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "GameplayTags/CallistoTags.h"
#include "Kismet/KismetMathLibrary.h"

void UCallisto_MeleeAttack::NotifyTick(
    USkeletalMeshComponent* MeshComp,
    UAnimSequenceBase* Animation,
    float FrameDeltaTime,
    const FAnimNotifyEventReference& EventReference)
{
    Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

    if (!IsValid(MeshComp)) return;
    if (!IsValid(MeshComp->GetOwner())) return;

    TArray<FHitResult> Hits = PerformSphereTrace(MeshComp);
    SendEventsToActors(MeshComp, Hits);
}

TArray<FHitResult> UCallisto_MeleeAttack::PerformSphereTrace(
    USkeletalMeshComponent* MeshComp) const
{
    TArray<FHitResult> OutHits;

    if (!IsValid(MeshComp)) return OutHits;
    if (!IsValid(MeshComp->GetOwner())) return OutHits;

    const FTransform SocketTransform =
        MeshComp->GetSocketTransform(SocketName);

    const FVector Start =
        SocketTransform.GetLocation();

    const FVector ExtendedSocketDirection =
        UKismetMathLibrary::GetForwardVector(
            SocketTransform.GetRotation().Rotator()
        ) * SocketExtensionOffset;

    const FVector End =
        Start - ExtendedSocketDirection;

    FCollisionQueryParams Params;
    Params.AddIgnoredActor(MeshComp->GetOwner());

    FCollisionResponseParams ResponseParams;
    ResponseParams.CollisionResponse.SetAllChannels(ECR_Ignore);
    ResponseParams.CollisionResponse.SetResponse(ECC_Pawn, ECR_Block);

    UWorld* World =
        GEngine->GetWorldFromContextObject(
            MeshComp,
            EGetWorldErrorMode::LogAndReturnNull
        );

    if (!IsValid(World)) return OutHits;

    const bool bHit =
        World->SweepMultiByChannel(
            OutHits,
            Start,
            End,
            FQuat::Identity,
            ECC_Visibility,
            FCollisionShape::MakeSphere(SphereTraceRadius),
            Params,
            ResponseParams
        );

#if !UE_BUILD_SHIPPING

    if (bDrawDebugs)
    {
        const FColor DebugColor =
            bHit ? FColor::Green : FColor::Red;

        DrawDebugSphere(
            World,
            Start,
            SphereTraceRadius,
            16,
            DebugColor,
            false,
            5.f
        );

        DrawDebugSphere(
            World,
            End,
            SphereTraceRadius,
            16,
            DebugColor,
            false,
            5.f
        );

        DrawDebugLine(
            World,
            Start,
            End,
            DebugColor,
            false,
            5.f
        );
    }

#endif

    return OutHits;
}

void UCallisto_MeleeAttack::SendEventsToActors(
    USkeletalMeshComponent* MeshComp,
    const TArray<FHitResult>& Hits) const
{
    if (!IsValid(MeshComp)) return;
    if (!IsValid(MeshComp->GetOwner())) return;

    for (const FHitResult& Hit : Hits)
    {
        ACallisto_PlayerCharacter* PlayerCharacter =
            Cast<ACallisto_PlayerCharacter>(Hit.GetActor());

        if (!IsValid(PlayerCharacter)) continue;
        if (!PlayerCharacter->IsAlive()) continue;

        UAbilitySystemComponent* ASC =
            PlayerCharacter->GetAbilitySystemComponent();

        if (!IsValid(ASC)) continue;

        FGameplayEffectContextHandle ContextHandle =
            ASC->MakeEffectContext();

        ContextHandle.AddHitResult(Hit);

        FGameplayEventData Payload;
        Payload.Target = PlayerCharacter;
        Payload.ContextHandle = ContextHandle;
        Payload.Instigator = MeshComp->GetOwner();

        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
            MeshComp->GetOwner(),
            CallistoTags::Events::Enemy::MeleeTraceHit,
            Payload
        );
    }
}