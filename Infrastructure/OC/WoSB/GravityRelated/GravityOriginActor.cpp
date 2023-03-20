// Fill out your copyright notice in the Description page of Project Settings.

// This file is only for setting up a default hierarchy for all GravityOriginActors,
// it has no other purpose

#include "GravityOriginActor.h"

// Sets default values
AGravityOriginActor::AGravityOriginActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	// Setup hierarchy
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollsiion"));

	RootComponent = StaticMesh;
	SphereCollision->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawned
void AGravityOriginActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGravityOriginActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Tick is set to false

}

