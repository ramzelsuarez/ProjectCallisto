// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "Callisto_BaseCharacter.h"
#include "Callisto_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PROJECTCALLISTO_API ACallisto_PlayerCharacter : public ACallisto_BaseCharacter
{
	GENERATED_BODY()

public:
	ACallisto_PlayerCharacter();
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};
