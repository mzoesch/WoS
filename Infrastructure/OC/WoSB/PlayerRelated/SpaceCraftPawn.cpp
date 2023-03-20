// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceCraftPawn.h"

// Sets default values
ASpaceCraftPawn::ASpaceCraftPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup hierarchy
	TmpCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TmpCamera"));
	AffectedByGravityActorComponent = CreateDefaultSubobject<UAffectedByGravityActorComponent>(TEXT("AffectedByGravityActorComponent"));
	PlayerCanEnterSpaceCraftSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("PlayerCanEnterSpaceCraftSphereComponent"));
	SpaceCraftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpaceCraftMesh"));

	// RootComponent = SpaceCraftMesh;
	TmpCamera->SetupAttachment(RootComponent);
	PlayerCanEnterSpaceCraftSphereComponent->SetupAttachment(RootComponent);
	SpaceCraftMesh->SetupAttachment(RootComponent);

	SpaceCraftPrimitiveComponent = Cast<UPrimitiveComponent>(this->GetComponentByClass(UPrimitiveComponent::StaticClass()));

}

// Called when the game starts or when spawned
void ASpaceCraftPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceCraftPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ASpaceCraftPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftStraight"), this, &ASpaceCraftPawn::PlayerMoveSpaceCraftStraight);
	// PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftSideways"), this, &ASpaceCraftPawn::PlayerMoveSpaceCraftSideways);
	// PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftVertically"), this, &ASpaceCraftPawn::PlayerMoveSpaceCraftVertically);
	// 
	// PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftYaw"), this, &ASpaceCraftPawn::PlayerRotateSpaceCraftYaw);
	// PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftPitch"), this, &ASpaceCraftPawn::PlayerRotateSpaceCraftPitch);
	// PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftRoll"), this, &ASpaceCraftPawn::PlayerRotateSpaceCraftRoll);

}

#pragma region Player and camera movement (SpaceCraft)

// void ASpaceCraftPawn::PlayerMoveSpaceCraftStraight(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftMoveStraight(this, SpaceCraftPrimitiveComponent, Value); }
// void ASpaceCraftPawn::PlayerMoveSpaceCraftSideways(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftMoveSideways(this, SpaceCraftPrimitiveComponent, Value); }
// void ASpaceCraftPawn::PlayerMoveSpaceCraftVertically(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftMoveVertically(this, SpaceCraftPrimitiveComponent, Value); }
// 
// void ASpaceCraftPawn::PlayerRotateSpaceCraftYaw(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftRotateYaw(this, SpaceCraftPrimitiveComponent, Value); }
// void ASpaceCraftPawn::PlayerRotateSpaceCraftPitch(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftRotatePitch(this, SpaceCraftPrimitiveComponent, Value); }
// void ASpaceCraftPawn::PlayerRotateSpaceCraftRoll(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftRotateRoll(this, SpaceCraftPrimitiveComponent, Value); }

#pragma endregion
