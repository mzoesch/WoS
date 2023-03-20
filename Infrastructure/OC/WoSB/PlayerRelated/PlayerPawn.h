// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Engine/StaticMesh.h"
#include "Camera/CameraComponent.h"
#include "../GravityRelated/AffectedByGravityActorComponent.h"
#include "../ImportantQuaternionFuntionsClass.h"
#include "Movement/PlayerMovementFootClass.h"

#include "PlayerPawn.generated.h"

UCLASS()
class WORLDOFSTARS_API APlayerPawn : public APawn, public PlayerMovementFootClass
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

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
		bool CanEnter = false;

private:

	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* PlayerMesh;
	UPROPERTY(EditDefaultsOnly)
		UCameraComponent* FPPlayerCamera;
	// TPPlayer Camera - just to view - NOT to play
	UPROPERTY(EditDefaultsOnly)
		UAffectedByGravityActorComponent* AffectedByGravityActorComponent;



	// NOTE: Values may get very high although an actor moves slowly
	int PlayerMaxMovementFootMagnitude = 100000;
	int PlayerDecelerationFoot = 10000;


#pragma region Player and camera movement (Foot)

	void PlayerMoveFootStraight(float Value);
	void PlayerMoveFootSideways(float Value);

	void PlayerRotateFootYaw(float Value);
	void PlayerRotateFootPitch(float Value);
	void PlayerRotateFootRoll(float Value);

	void DecreseAngularSpeedFoot(float deceleration);

#pragma endregion

	// Auto assign
	UPrimitiveComponent* PlayerFootPrimitiveComponent;	

};
