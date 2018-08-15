// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CICAIController.generated.h"

/**
 * 
 */

class UChiappaETiraComponent;

UCLASS()
class CACIARAINCLASSE_API ACICAIController : public AAIController
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		AActor* GetActorToPick();
	UFUNCTION(BlueprintCallable)
	void PickUp();
	

	UPROPERTY(BlueprintReadOnly)
	bool Grabbing = false;

	virtual void BeginPlay() override;

private:
	FHitResult LookForActorsInRange();
	
	UChiappaETiraComponent* Chiappa = nullptr;
	
	
};
