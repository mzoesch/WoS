// Fill out your copyright notice in the Description page of Project Settings.

// All functions and variables are for moving the player (Foot)

#pragma once

#include "../../ImportantQuaternionFuntionsClass.h"
#include "CoreMinimal.h"

/**
 * 
 */
static class WORLDOFSTARS_API PlayerMovementFootClass
{
public:
	PlayerMovementFootClass();
	~PlayerMovementFootClass();

protected:

	void PlayerMoveStraight(AActor* Actor, float Value);
	void PlayerMoveSideways(AActor* Actor, float Value);
	void PlayerRotateYaw(AActor* Actor, float Value);
	void PlayerRotatePitch(AActor* Actor, float Value);
	void PlayerRotateRoll(AActor* Actor, float Value);

public:

	// Values to move the player
	// NOTE: This values should not be changed
	// only if the player received an upgrade for example
	float PlayerMovementSpeed = 5;

private:

	// In UE settings are sensitivity settings
	// Do not change the sensitivity with these values to change camera speed
	// These values should be the default values when multiplying with 1
	float RotationSpeedYaw = 1.f; // How fast the player can turn sideways (mouse sensitivity x)
	float RotationSpeedPitch = 1.f; // How fast the player can look up / down (mouse sensitivity y)
	float RotationSpeedRoll = 1.f; // How fast the player can roll

};
