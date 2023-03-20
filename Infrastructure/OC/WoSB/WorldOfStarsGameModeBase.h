// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "GameFramework/DefaultPawn.h"
#include "PlayerRelated/PlayerPawn.h"

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
		TSubclassOf<APlayerPawn> UsedPawn = APlayerPawn::StaticClass();

};
