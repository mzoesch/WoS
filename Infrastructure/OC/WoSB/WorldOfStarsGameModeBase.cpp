// Copyright Epic Games, Inc. All Rights Reserved.


#include "WorldOfStarsGameModeBase.h"


void AWorldOfStarsGameModeBase::InitGameState()
{
	Super::InitGameState();

	// Check if no hard override is active
	if (DefaultPawnClass == ADefaultPawn::StaticClass())
		DefaultPawnClass = UsedPawn;

}
