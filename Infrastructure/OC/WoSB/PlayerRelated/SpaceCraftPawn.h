// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Engine/StaticMesh.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "../GravityRelated/AffectedByGravityActorComponent.h"
#include "../ImportantQuaternionFuntionsClass.h"
#include "Movement/PlayerMovementSpaceCraftClass.h"
#include "Components/SphereComponent.h"

#include "SpaceCraftPawn.generated.h"

UCLASS()
class WORLDOFSTARS_API ASpaceCraftPawn : public APawn, public PlayerMovementSpaceCraftClass
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

public:

	UPROPERTY(BlueprintReadWrite)
		bool SpaceCraftCanBeEntered = false;
	UPROPERTY(BlueprintReadWrite)
		AActor* PlayerThatEnteredTheStarCraft = nullptr;

private:

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* SpaceCraftMesh;
	UPROPERTY(EditDefaultsOnly)
		UCameraComponent* TmpCamera;
	UPROPERTY(EditDefaultsOnly)
		UAffectedByGravityActorComponent* AffectedByGravityActorComponent;
	UPROPERTY(EditDefaultsOnly)
		USphereComponent* PlayerCanEnterSpaceCraftSphereComponent;

protected:

#pragma region Player and camera movement (SpaceCraft)

	// void PlayerMoveSpaceCraftStraight(float Value);
	// void PlayerMoveSpaceCraftSideways(float Value);
	// void PlayerMoveSpaceCraftVertically(float Value);

	// void PlayerRotateSpaceCraftYaw(float Value);
	// void PlayerRotateSpaceCraftPitch(float Value);
	// void PlayerRotateSpaceCraftRoll(float Value);

#pragma endregion

	// Auto assign
	UPrimitiveComponent* SpaceCraftPrimitiveComponent;

};
