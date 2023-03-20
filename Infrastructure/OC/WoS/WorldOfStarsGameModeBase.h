// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "PlayerRelated/SpaceCrafts/SpaceCraftPawn.h"
#include "GameFramework/DefaultPawn.h"

#include "WorldOfStarsGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class WORLDOFSTARS_API AWorldOfStarsGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	void InitGameState() override;

private:

	UPROPERTY(EditAnywhere, NoClear)
		TSubclassOf<APawn> PawnToSetInLevel = APawn::StaticClass();
		
};
