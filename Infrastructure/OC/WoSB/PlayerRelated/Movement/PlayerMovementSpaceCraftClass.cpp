// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovementSpaceCraftClass.h"

PlayerMovementSpaceCraftClass::PlayerMovementSpaceCraftClass()
{
}

PlayerMovementSpaceCraftClass::~PlayerMovementSpaceCraftClass()
{
}

#pragma region SpaceCraft movement - a SpaceCraft is moved by force only!

void PlayerMovementSpaceCraftClass::SpaceCraftMoveStraight(AActor* Actor,
	UPrimitiveComponent* SpaceCraftPrimitiveComponent, float Value)
{
	
	FVector forceToAdd;
	forceToAdd = Actor->GetActorForwardVector() * Value * SpaceCraftAcceleration;
	// SpaceCraftPrimitiveComponent->AddForce(forceToAdd);
	
	// Cast<UPrimitiveComponent>(Actor->GetComponentByClass(UPrimitiveComponent::StaticClass()))
	// 	->AddForce(forceToAdd);

	UPrimitiveComponent* PC = Cast<UPrimitiveComponent>(Actor->GetComponentByClass(UPrimitiveComponent::StaticClass()));
	PC->AddForce(forceToAdd);


	UE_LOG(LogTemp, Warning, TEXT("SpaceCraft f: %s"), *forceToAdd.ToString()); // Just for debugging

}

void PlayerMovementSpaceCraftClass::SpaceCraftMoveSideways(AActor* Actor,
	UPrimitiveComponent* SpaceCraftPrimitiveComponent, float Value)
{

	FVector forceToAdd;
	forceToAdd = Actor->GetActorRightVector() * Value * SpaceCraftAcceleration;
	// SpaceCraftPrimitiveComponent->AddForce(forceToAdd);

	// UE_LOG(LogTemp, Warning, TEXT("SpaceCraft r: %s"), *forceToAdd.ToString()); // Just for debugging

}

void PlayerMovementSpaceCraftClass::SpaceCraftMoveVertically(AActor* Actor,
	UPrimitiveComponent* SpaceCraftPrimitiveComponent, float Value)
{
	
	FVector forceToAdd;
	forceToAdd = Actor->GetActorUpVector() * Value * SpaceCraftAcceleration;
	// SpaceCraftPrimitiveComponent->AddForce(forceToAdd);

	// UE_LOG(LogTemp, Warning, TEXT("SpaceCraft u: %s"), *forceToAdd.ToString()); // Just for debugging

}



void PlayerMovementSpaceCraftClass::SpaceCraftRotateYaw(AActor* Actor, float Value)
{

	FQuat q = ImportantQuaternionFuntionsClass::EulerToQuaternion(FRotator(0, Value, 0));
	ImportantQuaternionFuntionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);
	
}

void PlayerMovementSpaceCraftClass::SpaceCraftRotatePitch(AActor* Actor, float Value)
{

	FQuat q = ImportantQuaternionFuntionsClass::EulerToQuaternion(FRotator(-Value, 0, 0));
	ImportantQuaternionFuntionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);

}

void PlayerMovementSpaceCraftClass::SpaceCraftRotateRoll(AActor* Actor, float Value)
{

	FQuat q = ImportantQuaternionFuntionsClass::EulerToQuaternion(FRotator(0, 0, -Value));
	ImportantQuaternionFuntionsClass::AddActorRelativeRotationFromQuaternion(Actor, q);

}

#pragma endregion

#pragma region Camera movement 



#pragma endregion
