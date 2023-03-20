// Fill out your copyright notice in the Description page of Project Settings.

// All functions and variables are for moving the player (SpaceCraft)

#pragma once

#include "../../ImportantQuaternionFuntionsClass.h"
#include "CoreMinimal.h"

/**
 * 
 */
static class WORLDOFSTARS_API PlayerMovementSpaceCraftClass
{
public:
	PlayerMovementSpaceCraftClass();
	~PlayerMovementSpaceCraftClass();
	
protected:

	void SpaceCraftMoveStraight(AActor* Actor, UPrimitiveComponent* SpaceCraftPrimitiveComponent, float Value);
	void SpaceCraftMoveSideways(AActor* Actor, UPrimitiveComponent* SpaceCraftPrimitiveComponent, float Value);
	void SpaceCraftMoveVertically(AActor* Actor, UPrimitiveComponent* SpaceCraftPrimitiveComponent, float Value);

	void SpaceCraftRotateYaw(AActor* Actor, float Value);
	void SpaceCraftRotatePitch(AActor* Actor, float Value);
	void SpaceCraftRotateRoll(AActor* Actor, float Value);

public:

	// Values to move the SpaceCraft
	// NOTE: This values should not be changed
	// only if the SpaceCraft received an upgrade for example
	// Implement this later in an interface to quickly add multiply SpaceCrafts
	// with different stats - customizable??
	float SpaceCraftAcceleration = 100000;

private:

	float RotationSpeedYaw = 1.f; // How fast the SpaceCraft can turn sideways
	float RotationSpeedPitch = 1.f; // How fast the SpaceCraft can turn up and down
	float RotationSpeedRoll = 1.f; // How fast the SpaceCraft can roll

};
