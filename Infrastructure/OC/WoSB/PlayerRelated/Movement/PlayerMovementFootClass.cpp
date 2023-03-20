// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementFootClass.h"

PlayerMovementFootClass::PlayerMovementFootClass()
{
}

PlayerMovementFootClass::~PlayerMovementFootClass()
{
}

#pragma region Player movement

void PlayerMovementFootClass::PlayerMoveStraight(AActor* Actor, float Value)
{
	
	float veloctiy = Value * PlayerMovementSpeed;
	
	FVector direction = Actor->GetActorForwardVector();
	direction.Normalize();

	Actor->SetActorLocation(Actor->GetActorLocation() + direction * veloctiy);

	// UE_LOG(LogTemp, Warning, TEXT("FT st: %f"), veloctiy); // Just for debugging

}

void PlayerMovementFootClass::PlayerMoveSideways(AActor* Actor, float Value)
{

	float veloctiy = Value * PlayerMovementSpeed;

	FVector direction = Actor->GetActorRightVector();
	direction.Normalize();

	Actor->SetActorLocation(Actor->GetActorLocation() + direction * veloctiy);

	// UE_LOG(LogTemp, Warning, TEXT("FT sw: %f"), veloctiy); // Just for debugging
	
}

#pragma endregion

#pragma region Camera movement



void PlayerMovementFootClass::PlayerRotateYaw(AActor* Actor,float Value)
{

	FQuat q = ImportantQuaternionFuntionsClass::EulerToQuaternion(FRotator(0, Value * RotationSpeedYaw, 0));
	ImportantQuaternionFuntionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);

}

void PlayerMovementFootClass::PlayerRotatePitch(AActor* Actor, float Value)
{

	FQuat q = ImportantQuaternionFuntionsClass::EulerToQuaternion(FRotator(-Value * RotationSpeedPitch, 0, 0));
	ImportantQuaternionFuntionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);

}

void PlayerMovementFootClass::PlayerRotateRoll(AActor* Actor, float Value)
{

	FQuat q = ImportantQuaternionFuntionsClass::EulerToQuaternion(FRotator(0, 0, -Value * RotationSpeedRoll));
	ImportantQuaternionFuntionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);

}

#pragma endregion
