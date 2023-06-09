// © 2022 mzoesch. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CapsuleComponent.h"

#include "AC_CharacterMovementController.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WOS_API UAC_CharacterMovementController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_CharacterMovementController();

public:
	// Vars
	float epsilon = .01f;

	// Properties
	UPROPERTY(BlueprintReadWrite) float MoveStraight;
	UPROPERTY(BlueprintReadWrite) float MoveSideways;

	UPROPERTY(BlueprintReadOnly) float FootWalkingSpeed = 300; // cm / h
	UPROPERTY(BlueprintReadOnly) float NinjaWalkingSpeed = 900; // cm / h
	UPROPERTY(BlueprintReadOnly) float FootCrouchingSpeed = 350; // This is not real speed ?? Reduction is automaticlly applied in Ninja?
	float TempADSReduction = .5f;

	// Methods
	// Movement-Control functions for Player states
	// Should only be called in BP
	UFUNCTION(BlueprintCallable) void FootMovement(APawn* Pawn, AController* Controller, UCapsuleComponent* CapsuleComponent,
		float StraightScale, float SidewaysScale,
		bool WantsRun, bool WantsCrouch, bool IsADS);

	FVector CalcDirMoveStraight(AController* Con, UCapsuleComponent* Capsule);
	FVector CalcDirMoveSideways(AController* Con);
};
