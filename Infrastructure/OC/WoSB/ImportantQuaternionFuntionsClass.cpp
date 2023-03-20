// Fill out your copyright notice in the Description page of Project Settings.



#include "ImportantQuaternionFuntionsClass.h"

ImportantQuaternionFuntionsClass::ImportantQuaternionFuntionsClass()
{
}

ImportantQuaternionFuntionsClass::~ImportantQuaternionFuntionsClass()
{
}


#pragma region Quaternion calculations for yaw, pitch, roll

FQuat ImportantQuaternionFuntionsClass::EulerToQuaternion(FRotator EulerRotation)
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



void ImportantQuaternionFuntionsClass::SetWorldRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotateTo)
{

	if (!SceneComponent) return;
	SceneComponent->SetWorldRotation(RotateTo);

}
	
void ImportantQuaternionFuntionsClass::SetRelativeRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotateTo)
{

	if (!SceneComponent) return;
	SceneComponent->SetRelativeRotation(RotateTo);

}

void ImportantQuaternionFuntionsClass::AddLocalRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotationToAdd)
{

	if (!SceneComponent) return;
	SceneComponent->AddLocalRotation(RotationToAdd);

}



void ImportantQuaternionFuntionsClass::SetActorWorldRotationFromQuaternion(AActor* Actor, const FQuat& RotateTo)
{

	if (!Actor) return;
	Actor->SetActorRotation(RotateTo);

}

void ImportantQuaternionFuntionsClass::SetActorRelativeRotationFromQuaternion(AActor* Actor, const FQuat& RotateTo)
{

	if (!Actor) return;
	Actor->SetActorRelativeRotation(RotateTo);

}

void ImportantQuaternionFuntionsClass::AddActorRelativeRotationFromQuaternion(AActor* Actor, const FQuat& RotationToAdd)
{

	if (!Actor) return;
	Actor->AddActorLocalRotation(RotationToAdd);

}

#pragma endregion
