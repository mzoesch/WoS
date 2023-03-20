// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstSpaceFighterPawn.h"

// Sets default values
AFirstSpaceFighterPawn::AFirstSpaceFighterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup hierarchy
	OutsideCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OutsideCamera"));
	// AffectedByGravityActorComponent = CreateDefaultSubobject<UAffectedByGravityActorComponent>(TEXT("AffectedByGravityActorComponent"));
	// PlayerCanEnterSpaceCraftSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("PlayerCanEnterSpaceCraftSphereComponent"));
	MainBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainBody"));
	MeshRootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshRootComponent"));

	RootComponent = MeshRootComponent;
	OutsideCamera->SetupAttachment(MeshRootComponent);
	// PlayerCanEnterSpaceCraftSphereComponent->SetupAttachment(MeshRootComponent);
	MainBody->SetupAttachment(MeshRootComponent);


	SpaceCraftPrimitiveComponent = Cast<UPrimitiveComponent>(this->GetComponentByClass(UPrimitiveComponent::StaticClass()));

}

// Called when the game starts or when spawned
void AFirstSpaceFighterPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstSpaceFighterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstSpaceFighterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftStraight"), this, &AFirstSpaceFighterPawn::MoveSpaceCraftStraight);
	PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftSideways"), this, &AFirstSpaceFighterPawn::MoveSpaceCraftSideways);
	PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftVertically"), this, &AFirstSpaceFighterPawn::MoveSpaceCraftVertically);

	PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftYaw"), this, &AFirstSpaceFighterPawn::RotateSpaceCraftYaw);
	PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftPitch"), this, &AFirstSpaceFighterPawn::RotateSpaceCraftPitch);
	PlayerInputComponent->BindAxis(TEXT("PlayerMoveSpaceCraftRoll"), this, &AFirstSpaceFighterPawn::RotateSpaceCraftRoll);

}

#pragma region SpaceCraft movement

void AFirstSpaceFighterPawn::MoveSpaceCraftStraight(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftMoveStraight(this, SpaceCraftPrimitiveComponent, Value); }
void AFirstSpaceFighterPawn::MoveSpaceCraftSideways(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftMoveSideways(this, SpaceCraftPrimitiveComponent, Value); }
void AFirstSpaceFighterPawn::MoveSpaceCraftVertically(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftMoveVertically(this, SpaceCraftPrimitiveComponent, Value); }

void AFirstSpaceFighterPawn::RotateSpaceCraftYaw(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftRotateYaw(this, Value); }
void AFirstSpaceFighterPawn::RotateSpaceCraftPitch(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftRotatePitch(this, Value); }
void AFirstSpaceFighterPawn::RotateSpaceCraftRoll(float Value) { PlayerMovementSpaceCraftClass::SpaceCraftRotateRoll(this, Value); }

#pragma endregion


