// Copyright Zel Suarez

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Callisto_PlayerController.generated.h"

struct FGameplayTag;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class PROJECTCALLISTO_API ACallisto_PlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void SetupInputComponent() override;
	
private:
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Input|Movement")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Input|Movement")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Input|Movement")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Callisto|Input|Abilities")
	TObjectPtr<UInputAction> PrimaryAction;
	
	void Jump();
	void StopJumping();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Primary();
	void ActivateAbility(const FGameplayTag& AbilityTag) const;
};
