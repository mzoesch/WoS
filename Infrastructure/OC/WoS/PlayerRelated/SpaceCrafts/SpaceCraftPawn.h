// © 2022 mzoesch. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Engine/StaticMesh.h"
#include "../GeneralVehicleInterface.h"
#include "Camera/CameraComponent.h"
#include "Movement/MovementControllerClass.h"
#include "Movement/ThrusterSceneComponent.h"
#include "Containers/Array.h"
#include "Engine/World.h"

#include "SpaceCraftPawn.generated.h"

UCLASS()
class WORLDOFSTARS_API ASpaceCraftPawn : public APawn, public MovementControllerClass
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceCraftPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly)
		UCameraComponent* OutsideCamera;

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* MainBodyMesh; // The mesh body of the StarCraft
	// Later add all other meshes as submeshes here to make movements / animations

#pragma region Thrustergroups

	TArray<UActorComponent*> AllThrusterOnSpaceCraft;

	// TODO: For moveing too!

	TArray<UThrusterSceneComponent*> ThrustersYaw;
	TArray<UThrusterSceneComponent*> ThrustersPitch;
	TArray<UThrusterSceneComponent*> ThrustersRoll;


#pragma endregion


#pragma region Move the SpaceCraft

	// Functions are called by blueprints
	// All movement is done by blueprints

	UFUNCTION(BlueprintCallable)
		void MoveStraight(float Value);
	UFUNCTION(BlueprintCallable)
		void MoveSideways(float Value);
	UFUNCTION(BlueprintCallable)
		void MoveVertically(float Value);

	UFUNCTION(BlueprintCallable)
		void RotateYaw(float Value);
	UFUNCTION(BlueprintCallable)
		void RotatePitch(float Value);
	UFUNCTION(BlueprintCallable)
		void RotateRoll(float Value);

	// To calculate all contra forces to stop a SpaceCraft as fast as possible
	FRotator RotationLastFrame = FRotator(.0f, .0f, .0f);
	double DeadSpace = 0.01;

	UPROPERTY(BlueprintReadWrite)
		bool RotatingYaw = false;
	UPROPERTY(BlueprintReadWrite)
		bool RotatingPitch = false;
	UPROPERTY(BlueprintReadWrite)
		bool RotatingRoll = false;

#pragma endregion

	// Auto assign
	UPrimitiveComponent* SpaceCraftPrimitiveComponent;

private:

	void DecelerateSpaceCraft();

};
