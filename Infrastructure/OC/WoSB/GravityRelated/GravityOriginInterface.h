// Fill out your copyright notice in the Description page of Project Settings.

// This interface is only for detecting which actor can impact other
// actors via gravity - is has no other purpose

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GravityOriginInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGravityOriginInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WORLDOFSTARS_API IGravityOriginInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

};
