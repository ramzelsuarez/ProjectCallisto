// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Callisto_MeleeAttack.generated.h"


UCLASS()
class PROJECTCALLISTO_API UCallisto_MeleeAttack : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
	
private:
	
	UPROPERTY(EditAnywhere, Category = "Callisto|Debugs")
	bool bDrawDebugs = true;
	
	UPROPERTY(EditAnywhere, Category = "Callisto|Socket")
	FName SocketName{"FX_Trail_01_R"};
	
	UPROPERTY(EditAnywhere, Category = "Callisto|Socket")
	float SocketExtensionOffset{40.f};
	
	UPROPERTY(EditAnywhere, Category = "Callisto|Socket")
	float SphereTraceRadius{60.f};
	
	TArray<FHitResult> PerformSphereTrace(USkeletalMeshComponent* MeshComp) const;
	void SendEventsToActors(USkeletalMeshComponent* MeshComp, const TArray<FHitResult>& Hits) const;
};
