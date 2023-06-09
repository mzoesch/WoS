// © 2022 mzoesch. All rights reserved.


#include "MovementControllerClass.h"
#include "Engine/World.h"


MovementControllerClass::MovementControllerClass()
{
}

MovementControllerClass::~MovementControllerClass()
{
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Move these code to the specific .cpp classes in this folder
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void MovementControllerClass::CalculateMoveStraight(AActor* Actor, UPrimitiveComponent* PrimitiveComponent, float Value)
{
	
	FVector forceToAdd;
	forceToAdd = Actor->GetActorForwardVector() * Value * 250000.f;

	PrimitiveComponent->AddForce(forceToAdd);

}

void MovementControllerClass::CalculateMoveSideways(AActor* Actor, UPrimitiveComponent* PrimitiveComponent, float Value)
{
	
	FVector forceToAdd;
	forceToAdd = Actor->GetActorRightVector() * Value * 250000.f;

	PrimitiveComponent->AddForce(forceToAdd);

}

void MovementControllerClass::CalculateMoveVertically(AActor* Actor, UPrimitiveComponent* PrimitiveComponent, float Value)
{
	
	FVector forceToAdd;
	forceToAdd = Actor->GetActorUpVector() * Value * 250000.f;

	PrimitiveComponent->AddForce(forceToAdd);

}

// Not rotation but also forces!!!!

void MovementControllerClass::CalculateRotateYaw(UPrimitiveComponent* PrimitiveComponent, TArray<UThrusterSceneComponent*> Thrusters, float Value)
{

	// New rotation with forces
	// NOTE: Thruster should be rotated in the DefaultsMenu, so here the function only
	// has to get the forward vector of each thruster
	for (UThrusterSceneComponent* tsc : Thrusters)
	{
		
		FVector torqueToAdd;
		torqueToAdd = tsc->GetRelativeRotation().Vector() * tsc->MaxForceToAdd * Value;
		PrimitiveComponent->AddTorqueInRadians(torqueToAdd);

		// FVector forceToAdd;
		// forceToAdd = tsc->GetRelativeRotation().Vector() * tsc->MaxForceToAdd * Value;
		// PrimitiveComponent->AddForceAtLocationLocal(-forceToAdd, tsc->GetRelativeLocation());
	
	}
	

	// Old rotation with quaternions
	// FQuat q = QuaternionFunctionsClass::EulerToQuaternion(FRotator(0, Value, 0));
	// QuaternionFunctionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);

}

void MovementControllerClass::CalculateRotatePitch(UPrimitiveComponent* PrimitiveComponent, TArray<UThrusterSceneComponent*> Thrusters, float Value)
{
	
	// New rotation with forces
	// NOTE: Thruster should be rotated in the DefaultsMenu, so here the function only
	// has to get the forward vector of each thruster

	for (UThrusterSceneComponent* tsc : Thrusters)
	{
		
		FVector torqueToAdd;
		torqueToAdd = tsc->GetRelativeRotation().Vector() * tsc->MaxForceToAdd * Value;
		PrimitiveComponent->AddTorqueInRadians(torqueToAdd);
		

		// OLD
		// FVector forceToAdd;
		// forceToAdd = tsc->GetRelativeRotation().Vector() * tsc->MaxForceToAdd * Value;
		// PrimitiveComponent->AddForceAtLocationLocal(-forceToAdd, tsc->GetRelativeLocation());
	
	}


	// Old rotation with quaternions
	// FQuat q = QuaternionFunctionsClass::EulerToQuaternion(FRotator(Value, 0, 0));
	// QuaternionFunctionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);

}

void MovementControllerClass::CalculateRotateRoll(UPrimitiveComponent* PrimitiveComponent, TArray<UThrusterSceneComponent*> Thrusters, float Value)
{
	
	// New rotation with forces
	// NOTE: Thruster should be rotated in the DefaultsMenu, so here the function only
	// has to get the forward vector of each thruster
	for (UThrusterSceneComponent* tsc : Thrusters)
	{

		FVector torqueToAdd;
		torqueToAdd = tsc->GetRelativeRotation().Vector() * tsc->MaxForceToAdd * Value;
		PrimitiveComponent->AddTorqueInRadians(-torqueToAdd);

		// OLD
		// FVector forceToAdd;
		// forceToAdd = tsc->GetRelativeRotation().Vector() * tsc->MaxForceToAdd * Value;
		// PrimitiveComponent->AddForceAtLocationLocal(-forceToAdd, tsc->GetRelativeLocation());

	}


	// Old rotation with quaternions
	// FQuat q = QuaternionFunctionsClass::EulerToQuaternion(FRotator(0, 0, -Value));
	// QuaternionFunctionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);

}
