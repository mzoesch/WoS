// © 2022 mzoesch. All rights reserved.


#include "DefaultWeapon.h"

// Sets default values
ADefaultWeapon::ADefaultWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup hierarchy
	MainWeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SKM_Weapon"));
	RootComponent = MainWeaponMesh;

}

// Called when the game starts or when spawned
void ADefaultWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefaultWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

