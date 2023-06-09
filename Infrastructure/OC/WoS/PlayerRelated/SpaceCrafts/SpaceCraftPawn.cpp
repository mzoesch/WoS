// © 2022 mzoesch. All rights reserved.


#include "SpaceCraftPawn.h"

// Sets default values
ASpaceCraftPawn::ASpaceCraftPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup hierarchy
	OutsideCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OutsideCamera"));
	MainBodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainBodyMesh"));

	RootComponent = MainBodyMesh;
	OutsideCamera->SetupAttachment(MainBodyMesh);

	SpaceCraftPrimitiveComponent = Cast<UPrimitiveComponent>(this->GetComponentByClass(UPrimitiveComponent::StaticClass()));

}

// Called when the game starts or when spawned
void ASpaceCraftPawn::BeginPlay()
{
	Super::BeginPlay();

#pragma region Get all thrusters

	AllThrusterOnSpaceCraft = this->GetComponentsByClass(UThrusterSceneComponent::StaticClass());
	UE_LOG(LogTemp, Warning, TEXT("All thrusters: %d"), AllThrusterOnSpaceCraft.Num()); // Just for debugging

	for (UActorComponent* a : AllThrusterOnSpaceCraft)
	{

		UThrusterSceneComponent* tsc = Cast<UThrusterSceneComponent>(a);
		
		if (tsc->UsedForYaw)
			ThrustersYaw.Add(tsc);
		if (tsc->UsedForPitch)
			ThrustersPitch.Add(tsc);
		if (tsc->UsedForRoll)
			ThrustersRoll.Add(tsc);
	}

	UE_LOG(LogTemp, Warning, TEXT("Yaw thrusters: %d"), ThrustersYaw.Num()); // Just for debugging
	UE_LOG(LogTemp, Warning, TEXT("Pitch thrusters: %d"), ThrustersPitch.Num()); // Just for debugging
	UE_LOG(LogTemp, Warning, TEXT("Roll thrusters: %d"), ThrustersRoll.Num()); // Just for debugging

#pragma endregion
	
}

// Called every frame
void ASpaceCraftPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	DecelerateSpaceCraft();

}

// Called to bind functionality to input
void ASpaceCraftPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


#pragma region Move the SpaceCraft

void ASpaceCraftPawn::MoveStraight(float Value) { MovementControllerClass::CalculateMoveStraight(this, SpaceCraftPrimitiveComponent, Value); }
void ASpaceCraftPawn::MoveSideways(float Value) { MovementControllerClass::CalculateMoveSideways(this, SpaceCraftPrimitiveComponent, Value); }
void ASpaceCraftPawn::MoveVertically(float Value) { MovementControllerClass::CalculateMoveVertically(this, SpaceCraftPrimitiveComponent, Value); }

void ASpaceCraftPawn::RotateYaw(float Value) { MovementControllerClass::CalculateRotateYaw(SpaceCraftPrimitiveComponent, ThrustersYaw, Value); }
void ASpaceCraftPawn::RotatePitch(float Value) { MovementControllerClass::CalculateRotatePitch(SpaceCraftPrimitiveComponent, ThrustersPitch, Value); }
void ASpaceCraftPawn::RotateRoll(float Value) { MovementControllerClass::CalculateRotateRoll(SpaceCraftPrimitiveComponent, ThrustersRoll, Value);  }

#pragma endregion

#pragma region Decelerate SpaceCraft (All vectors and rotations)

// Calculating all contra forces to stop a SpaceCrtaft as fast as possible

double CalculateDecelerationYaw(double actorDeltaRotationYaw, FRotator currentRotation, double DeadSpace, FRotator RotationLastFrame) {

	if (actorDeltaRotationYaw <= DeadSpace && actorDeltaRotationYaw >= -DeadSpace) return 0;

	// Any object should never rotate faster than this
	// This is for gimbel problems with addition and subtraction
	if (actorDeltaRotationYaw > 10 || actorDeltaRotationYaw < -10)
	{
		
		UE_LOG(LogTemp, Warning, TEXT("Hit gimbel problem: Yaw ")); // Just for debugging
		return 0;
	
	}

	// Thrusters will always max push to decelerate
	// TODO: User changeable or auto changeable?? -> Now bug: SpaceCraft will overdecelerate
	double forceValue = .0;
	forceValue = actorDeltaRotationYaw > .0 ? 1 : -1;

	// UE_LOG(LogTemp, Warning, TEXT("Yaw: %f"), actorDeltaRotationYaw); // Just for debugging
	// UE_LOG(LogTemp, Warning, TEXT("fVa: %f"), forceValue); // Just for debugging

	return 0; // forceValue;

}

double CalculateDecelerationPitch(double actorDeltaRotationPitch, FRotator currentRotation, double DeadSpace, FRotator RotationLastFrame) {

	if (actorDeltaRotationPitch <= DeadSpace && actorDeltaRotationPitch >= -DeadSpace) return 0;

	// Any object should never rotate faster than this
	// This is for gimbel problems with addition and subtraction
	if (actorDeltaRotationPitch > 10 || actorDeltaRotationPitch < -10)
	{

		UE_LOG(LogTemp, Warning, TEXT("Hit gimbel problem: Pitch ")); // Just for debugging
		return 0;

	}

	// Thrusters will always max push to decelerate
	// TODO: User changeable or auto changeable?? -> Now bug: SpaceCraft will overdecelerate
	double forceValue = .0;
	forceValue = actorDeltaRotationPitch > .0 ? 1 : -1;
	
	// UE_LOG(LogTemp, Warning, TEXT("%f"), actorDeltaRotationPitch); // Just for debugging
	// UE_LOG(LogTemp, Warning, TEXT("%f"), forceValue); // Just for debugging

	if (currentRotation.Roll > -90 && currentRotation.Roll < 90)
		return 0; // -forceValue;
	return 0; // forceValue;

}

double CalculateDecelerationRoll(double actorDeltaRotationRoll, FRotator currentRotation, double DeadSpace, FRotator RotationLastFrame) {

	if (actorDeltaRotationRoll <= DeadSpace && actorDeltaRotationRoll >= -DeadSpace) return 0;

	// Any object should never rotate faster than this
	// This is for gimbel problems with addition and subtraction
	if (actorDeltaRotationRoll > 10 || actorDeltaRotationRoll < -10)
	{

		UE_LOG(LogTemp, Warning, TEXT("Hit gimbel problem: Roll ")); // Just for debugging
		return 0;

	}

	// Thrusters will always max push to decelerate
	// TODO: User changeable or auto changeable?? -> Now bug: SpaceCraft will overdecelerate
	double forceValue = .0;
	forceValue = actorDeltaRotationRoll > .0 ? 1 : -1;

	// UE_LOG(LogTemp, Warning, TEXT("dl: %f"), actorDeltaRotationRoll); // Just for debugging
	// UE_LOG(LogTemp, Warning, TEXT("FV: %f"), forceValue); // Just for debugging
	
	return 0; // forceValue;

}

void ASpaceCraftPawn::DecelerateSpaceCraft()
{

	FRotator actorCurrentRotation = this->GetActorRotation();
	FRotator actorDeltaRotation; actorDeltaRotation = RotationLastFrame - actorCurrentRotation;

	if (!RotatingYaw)
		RotateYaw(CalculateDecelerationYaw(actorDeltaRotation.Yaw, actorCurrentRotation, DeadSpace, RotationLastFrame));

	if (!RotatingPitch)
		RotatePitch(CalculateDecelerationPitch(actorDeltaRotation.Pitch, actorCurrentRotation, DeadSpace, RotationLastFrame));

	if (!RotatingRoll)
		RotateRoll(CalculateDecelerationRoll(actorDeltaRotation.Roll, actorCurrentRotation, DeadSpace, RotationLastFrame));

	 
	// UE_LOG(LogTemp, Warning, TEXT("%s"), *actorCurrentRotation.ToString()) // Just for debugging
	// UE_LOG(LogTemp, Warning, TEXT("Quat:  %s"), *actorCurrentRotation.ToString());

	RotationLastFrame = actorCurrentRotation;
}

#pragma endregion
