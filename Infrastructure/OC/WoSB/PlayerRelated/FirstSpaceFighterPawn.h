// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Components/SphereComponent.h"
#include "Camera/CameraComponent.h"
#include "../GravityRelated/AffectedByGravityActorComponent.h"
#include "Movement/PlayerMovementSpaceCraftClass.h"

#include "FirstSpaceFighterPawn.generated.h"

UCLASS()
class WORLDOFSTARS_API AFirstSpaceFighterPawn : public APawn, public PlayerMovementSpaceCraftClass
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFirstSpaceFighterPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(BlueprintReadWrite)
		bool SpaceCraftCanBeEntered = false;
	UPROPERTY(BlueprintReadWrite)
		AActor* PlayerThatEnteredTheSpaceCraft = nullptr;

private:

	// All meshes are applied in the Blueprint Editor

	UPROPERTY(EditDefaultsOnly)
		UCameraComponent* OutsideCamera;
	UPROPERTY(EditDefaultsOnly)
		UAffectedByGravityActorComponent* AffectedByGravityActorComponent;
	// UPROPERTY(EditDefaultsOnly) // Make custom Collsion Box
	// 	USphereComponent* PlayerCanEnterSpaceCraftSphereComponent;
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* MainBody;
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* MeshRootComponent;

#pragma region SpaceCraft and camera movement

	void MoveSpaceCraftStraight(float Value);
	void MoveSpaceCraftSideways(float Value);
	void MoveSpaceCraftVertically(float Value);

	void RotateSpaceCraftYaw(float Value);
	void RotateSpaceCraftPitch(float Value);
	void RotateSpaceCraftRoll(float Value);

#pragma endregion

	// Auto assign
	UPrimitiveComponent* SpaceCraftPrimitiveComponent;

};
