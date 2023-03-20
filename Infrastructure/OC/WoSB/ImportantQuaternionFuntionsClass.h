// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"

/**
* 
*/
static class WORLDOFSTARS_API ImportantQuaternionFuntionsClass
{
public:
	ImportantQuaternionFuntionsClass();
	~ImportantQuaternionFuntionsClass();

public:


	// Controll yaw, pitch and roll of an actor
	static FQuat EulerToQuaternion(FRotator EulerRotation);

	static void SetWorldRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotateTo);
	static void SetRelativeRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotateTo);

	static void AddLocalRotationFromQuaternion(USceneComponent* SceneComponent, const FQuat& RotationToAdd);

	static void AddActorRelativeRotationFromQuaternion(AActor* Actor, const FQuat& RotationToAdd);
	static void SetActorRelativeRotationFromQuaternion(AActor* Actor, const FQuat& RotateTo);
	static void SetActorWorldRotationFromQuaternion(AActor* Actor, const FQuat& RotateTo);
		
};
