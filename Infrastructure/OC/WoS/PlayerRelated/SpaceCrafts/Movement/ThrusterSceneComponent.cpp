// © 2022 mzoesch. All rights reserved.


#include "ThrusterSceneComponent.h"

// Sets default values for this component's properties
UThrusterSceneComponent::UThrusterSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Setup hierarchy
	DirectionPointer = CreateDefaultSubobject<UArrowComponent>(TEXT("DirectionPointer"));

	DirectionPointer->SetupAttachment(this);

}


// Called when the game starts
void UThrusterSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UThrusterSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

