// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CICAIController.generated.h"

/**
 * 
 */
UCLASS()
class CACIARAINCLASSE_API ACICAIController : public AAIController
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	FHitResult LookForActorsInRange();
	
	
	
};
