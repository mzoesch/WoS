// Fill out your copyright notice in the Description page of Project Settings.

// This component should be attached to all actors that
// are affected by gravity through a GravityOriginActor

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"

#include "AffectedByGravityActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WORLDOFSTARS_API UAffectedByGravityActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAffectedByGravityActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	AActor* Parent = NULL;
	UPrimitiveComponent* ParentPrimitiveComponent = NULL;

};
