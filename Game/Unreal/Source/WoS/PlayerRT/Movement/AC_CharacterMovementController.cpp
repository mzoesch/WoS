// © 2022 mzoesch. All rights reserved.

#include "AC_CharacterMovementController.h"

// Sets default values for this component's properties
UAC_CharacterMovementController::UAC_CharacterMovementController() {

	// Set this component to be initialized when the game starts, and to be ticked every frame. You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...


}

UFUNCTION(BlueprintCallable) void UAC_CharacterMovementController::FootMovement(APawn* Pawn, AController* Controller, UCapsuleComponent* CapsuleComponent,
	float StraightScale, float SidewaysScale,
	bool WantsRun, bool WantsCrouch, bool IsADS) {

#pragma region Validation

	if (Pawn == nullptr) return;
	if (Controller == nullptr) return;
	if (CapsuleComponent == nullptr) return;

	// Player is not moving
	if (FMath::Abs(StraightScale) <= this->epsilon &&
		FMath::Abs(SidewaysScale) <= this->epsilon) return;

#pragma endregion

	// Straight
	float SpeedThisFrameStraight = .0f;
	if (IsADS || WantsCrouch || StraightScale < 0) WantsRun = false; // Players can't run when ADS, crouching or walking backwards 
	if (WantsCrouch) SpeedThisFrameStraight = this->FootCrouchingSpeed; // Player is crouching
	else if (WantsRun) SpeedThisFrameStraight = this->NinjaWalkingSpeed; // Player is running
	else SpeedThisFrameStraight = this->FootWalkingSpeed; // Normal walking
	if (IsADS) SpeedThisFrameStraight *= (1 - TempADSReduction); // Apply speed reduction to player
	if (FMath::Abs(StraightScale) <= this->epsilon) this->MoveStraight = 0;
	else this->MoveStraight = StraightScale * (SpeedThisFrameStraight / this->NinjaWalkingSpeed); // Set value between 0 and 1
	
	// Sideways
	float SpeedThisFrameSideways = .0f;
	if (WantsCrouch) SpeedThisFrameSideways = this->FootCrouchingSpeed; // Player is crouching
	else SpeedThisFrameSideways = this->FootWalkingSpeed; // Normal walking
	if (IsADS) SpeedThisFrameSideways *= (1 - TempADSReduction); // Apply speed reduction to player
	if (FMath::Abs(SidewaysScale) <= this->epsilon) this->MoveSideways = 0;
	else this->MoveSideways = SidewaysScale * (SpeedThisFrameSideways / this->NinjaWalkingSpeed);

	FVector dirStraight = CalcDirMoveStraight(Controller, CapsuleComponent);
	FVector dirSideways = CalcDirMoveSideways(Controller);

	// Here, FVector correction

	Pawn->AddMovementInput(dirStraight, this->MoveStraight, false);
	Pawn->AddMovementInput(dirSideways, this->MoveSideways, false);

	return UFUNCTION(BlueprintCallable) void();
}

#pragma region Calculator functions

FVector UAC_CharacterMovementController::CalcDirMoveStraight(AController* Con, UCapsuleComponent* Capsule) {

	FRotator rot = Con->GetControlRotation();
	FVector controlRightVector = FRotationMatrix(rot).GetScaledAxis(EAxis::Y);
	rot = Capsule->GetComponentRotation();
	FVector capsuleUpVector = FRotationMatrix(rot).GetScaledAxis(EAxis::Z);
	FVector cross = FVector::CrossProduct(controlRightVector, capsuleUpVector);
	cross = cross.GetSafeNormal(this->epsilon);

	return cross;
}

FVector UAC_CharacterMovementController::CalcDirMoveSideways(AController* Con) {
	
	FRotator rot = Con->GetControlRotation();
	FVector controlRightVector = FRotationMatrix(rot).GetScaledAxis(EAxis::Y);

	return controlRightVector;
}

#pragma endregion
