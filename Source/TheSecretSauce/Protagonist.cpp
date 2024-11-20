// Fill out your copyright notice in the Description page of Project Settings.
#include "Protagonist.h"

#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"

void AProtagonist::BeginPlay()
{
	Super::BeginPlay();

	// Add Input Mapping Context
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
		(PlayerController->GetLocalPlayer());

		if (Subsystem)
		{
			Subsystem->AddMappingContext(ProtagonistMappingContext, 0);
		}
	}
}

void AProtagonist::Move(const FInputActionValue& InputValue)
{
	const FVector2d DirectionalValue2d = InputValue.Get<FVector2d>();
	AddMovementInput(FVector(1,0,0), DirectionalValue2d.X);
	AddMovementInput(FVector(0,1,0), DirectionalValue2d.Y);
}

void AProtagonist::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// set up action bindings
	// CastChecked -> crash the game if the cast fail!
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AProtagonist::Move);
	}
}
