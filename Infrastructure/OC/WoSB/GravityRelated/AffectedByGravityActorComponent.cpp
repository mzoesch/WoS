// Fill out your copyright notice in the Description page of Project Settings.


#include "AffectedByGravityActorComponent.h"
#include "GravityOriginInterface.h"

// Sets default values for this component's properties
UAffectedByGravityActorComponent::UAffectedByGravityActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Parent = this->GetOwner();
	if (Parent) ParentPrimitiveComponent = 
		Cast<UPrimitiveComponent>(Parent->GetComponentByClass(UPrimitiveComponent::StaticClass()));



}


// Called when the game starts
void UAffectedByGravityActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Helper funcs
AActor* IsOverlappingWithGravityActor(UPrimitiveComponent* PrimitiveComponentToCheck) {

	TArray<AActor*> OverlappingActors;
	PrimitiveComponentToCheck->GetOverlappingActors(OverlappingActors);

	for (AActor* ActorI : OverlappingActors) {
		if (ActorI->GetClass()->ImplementsInterface(UGravityOriginInterface::StaticClass())) return ActorI;
	}
	
	return nullptr;
}

// Called every frame
void UAffectedByGravityActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	// i. Check if inside of the bounds of a GravityOriginActor
	AActor* GravityActor = IsOverlappingWithGravityActor(ParentPrimitiveComponent);
	if (GravityActor == nullptr) return;

	// ii. Calculate FVector and FRotator to origin
	FVector DistanceToTravelThisTick = FVector(.0f, .0f, .0f);
	FVector ParentLocation = Parent->GetActorLocation();
	FVector GravityOrigin = GravityActor->GetActorLocation();

	DistanceToTravelThisTick = GravityOrigin - ParentLocation;
	
	// iii. Calculate acceleration and gravity force



	// iv. Move parent to actor origin
	ParentPrimitiveComponent->AddForce(DistanceToTravelThisTick * 10);
	UE_LOG(LogTemp, Warning, TEXT("%f"), DistanceToTravelThisTick.Size());

}
