// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputAction.h"
#include "CoreMinimal.h"
#include "PaperCharBase.h"
#include "TP_PickUpComponent.h"
#include "Protagonist.generated.h"

/**
 * 
 */
UCLASS()
class THESECRETSAUCE_API AProtagonist : public APaperCharBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	void EnhancedInputMove(const FInputActionValue& InputValue);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputMappingContext*  ProtagonistMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	const UInputAction* MoveAction;

	// called for movement input
	void Move(const FInputActionValue& InputValue);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};


