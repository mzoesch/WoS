// Fill out your copyright notice in the Description page of Project Settings.

// This actor will have a gravity impact to all
// actors that have a AffectedByGravityActorComponent.
// Attach this for example on planets

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SceneComponent.h"
#include "GravityOriginInterface.h"

#include "GravityOriginActor.generated.h"

UCLASS()
class WORLDOFSTARS_API AGravityOriginActor : public AActor, public IGravityOriginInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGravityOriginActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
		USphereComponent* SphereCollision;

};
