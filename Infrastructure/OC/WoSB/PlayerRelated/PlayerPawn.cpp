// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Setup hierarchy
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	FPPlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPPlayerCamera"));
	AffectedByGravityActorComponent = CreateDefaultSubobject<UAffectedByGravityActorComponent>(TEXT("AffectedByGravityActorComponent"));

	RootComponent = PlayerMesh;
	FPPlayerCamera->SetupAttachment(PlayerMesh);

	PlayerFootPrimitiveComponent = Cast<UPrimitiveComponent>(this->GetComponentByClass(UPrimitiveComponent::StaticClass()));

}


// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("PlayerMoveFootStraight"), this, &APlayerPawn::PlayerMoveFootStraight);
	PlayerInputComponent->BindAxis(TEXT("PlayerMoveFootSideways"), this, &APlayerPawn::PlayerMoveFootSideways);

	PlayerInputComponent->BindAxis(TEXT("PlayerRotateFootYaw"), this, &APlayerPawn::PlayerRotateFootYaw);
	PlayerInputComponent->BindAxis(TEXT("PlayerRotateFootPitch"), this, &APlayerPawn::PlayerRotateFootPitch);
	PlayerInputComponent->BindAxis(TEXT("PlayerRotateFootRoll"), this, &APlayerPawn::PlayerRotateFootRoll);

	


}


void APlayerPawn::DecreseAngularSpeedFoot(float deceleration)
{



}


#pragma region Player and camera movement

void APlayerPawn::PlayerMoveFootStraight(float Value) { PlayerMovementFootClass::PlayerMoveStraight(this, Value); }
void APlayerPawn::PlayerMoveFootSideways(float Value) { PlayerMovementFootClass::PlayerMoveSideways(this, Value); }

void APlayerPawn::PlayerRotateFootYaw(float Value) { PlayerMovementFootClass::PlayerRotateYaw(this, Value); }
void APlayerPawn::PlayerRotateFootPitch(float Value) { PlayerMovementFootClass::PlayerRotatePitch(this, Value); }
void APlayerPawn::PlayerRotateFootRoll(float Value) { PlayerMovementFootClass::PlayerRotateRoll(this, Value); }

#pragma endregion
