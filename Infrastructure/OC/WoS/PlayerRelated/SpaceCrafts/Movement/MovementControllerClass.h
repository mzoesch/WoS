// © 2022 mzoesch. All rights reserved.

// This middle class has currently now purpose
// Later calc here fuel, etc.

#pragma once

#include "CoreMinimal.h"
#include "../../../QuaternionFunctionsClass.h"
#include "ThrusterSceneComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"

/**
 * 
 */
static class WORLDOFSTARS_API MovementControllerClass : public QuaternionFunctionsClass
{
public:
	MovementControllerClass();
	~MovementControllerClass();

protected:

	void CalculateMoveStraight(AActor* Actor, UPrimitiveComponent* PrimitiveComponent, float Value);
	void CalculateMoveSideways(AActor* Actor, UPrimitiveComponent* PrimitiveComponent, float Value);
	void CalculateMoveVertically(AActor* Actor, UPrimitiveComponent* PrimitiveComponent, float Value);

	void CalculateRotateYaw(UPrimitiveComponent* PrimitiveComponent, TArray<UThrusterSceneComponent*> ThrustersForYaw, float Value);
	void CalculateRotatePitch(UPrimitiveComponent* PrimitiveComponent, TArray<UThrusterSceneComponent*> ThrustersForPitch, float Value);
	void CalculateRotateRoll(UPrimitiveComponent* PrimitiveComponent, TArray<UThrusterSceneComponent*> ThrustersForRoll, float Value);
	
};
