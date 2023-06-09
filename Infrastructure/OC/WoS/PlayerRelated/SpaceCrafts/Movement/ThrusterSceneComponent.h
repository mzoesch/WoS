// © 2022 mzoesch. All rights reserved.

// This component is needed so that the vehicle knows where to add forces

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"

#include "ThrusterSceneComponent.generated.h"



UCLASS( ClassGroup=(SpaceCraft), meta=(BlueprintSpawnableComponent) )
class WORLDOFSTARS_API UThrusterSceneComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UThrusterSceneComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
		bool UsedForYaw = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
		bool UsedForPitch = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "General")
		bool UsedForRoll = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Thruster specific options")
		float MaxForceToAdd = 15000000.f;
							
private:

	UArrowComponent* DirectionPointer;

};
