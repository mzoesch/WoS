// Copyright Epic Games, Inc. All Rights Reserved.

#include "WoSGameMode.h"
#include "UObject/ConstructorHelpers.h"

AWoSGameMode::AWoSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	// static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Third/FP/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	// DefaultPawnClass = PlayerPawnClassFinder.Class;

}
