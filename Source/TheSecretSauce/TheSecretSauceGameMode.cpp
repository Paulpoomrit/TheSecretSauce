// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheSecretSauceGameMode.h"
#include "TheSecretSauceCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATheSecretSauceGameMode::ATheSecretSauceGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
