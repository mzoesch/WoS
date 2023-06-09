// © 2022 mzoesch. All rights reserved.


#include "QuaternionFunctionsClass.h"

QuaternionFunctionsClass::QuaternionFunctionsClass()
{
}

QuaternionFunctionsClass::~QuaternionFunctionsClass()
{
}


#pragma region Quaternion calculations for yaw, pitch, roll

FQuat QuaternionFunctionsClass::EulerToQuaternion(FRotator EulerRotation)
{

	FQuat output;

	float yaw = EulerRotation.Yaw * PI / 180;
	float pitch = EulerRotation.Pitch * PI / 180;
	float roll = EulerRotation.Roll * PI / 180;

	double cosYaw = cos(yaw * 0.5);
	double sinYaw = sin(yaw * 0.5);

	double cosPitch = cos(pitch * 0.5);
	double sinPitch = sin(pitch * 0.5);

	double cosRoll = cos(roll * 0.5);
	double sinRoll = sin(roll * 0.5);

	output.W = cosYaw * cosPitch * cosRoll + sinYaw * sinPitch * sinRoll;
	output.X = cosYaw * cosPitch * sinRoll - sinYaw * sinPitch * cosRoll;
	output.Y = cosYaw * sinPitch * cosRoll + sinYaw * cosPitch * sinRoll;
	output.Z = sinYaw * cosPitch * cosRoll - cosYaw * sinPitch * sinRoll;

	return output;
}



void QuaternionFunctionsClass::SetWorldRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotateTo)
{

	if (!SceneComponent) return;
	SceneComponent->SetWorldRotation(RotateTo);

}

void QuaternionFunctionsClass::SetRelativeRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotateTo)
{

	if (!SceneComponent) return;
	SceneComponent->SetRelativeRotation(RotateTo);

}

void QuaternionFunctionsClass::AddLocalRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotationToAdd)
{

	if (!SceneComponent) return;
	SceneComponent->AddLocalRotation(RotationToAdd);

}



void QuaternionFunctionsClass::SetActorWorldRotationFromQuaternion(AActor* Actor, const FQuat& RotateTo)
{

	if (!Actor) return;
	Actor->SetActorRotation(RotateTo);

}

void QuaternionFunctionsClass::SetActorRelativeRotationFromQuaternion(AActor* Actor, const FQuat& RotateTo)
{

	if (!Actor) return;
	Actor->SetActorRelativeRotation(RotateTo);

}

void QuaternionFunctionsClass::AddActorRelativeRotationFromQuaternion(AActor* Actor, const FQuat& RotationToAdd)
{

	if (!Actor) return;
	Actor->AddActorLocalRotation(RotationToAdd);

}

#pragma endregion

