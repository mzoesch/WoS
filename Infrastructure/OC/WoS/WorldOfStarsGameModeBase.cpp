// Copyright Epic Games, Inc. All Rights Reserved.


#include "WorldOfStarsGameModeBase.h"

void AWorldOfStarsGameModeBase::InitGameState()
{

	Super::InitGameState();

	// Only changes pawn if there is no hard override active
	if (DefaultPawnClass == ADefaultPawn::StaticClass())
		DefaultPawnClass = PawnToSetInLevel;

}
