// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChiappaETiraComponent.generated.h"


class UPhysicsHandleComponent;
class UAttachMesh;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CACIARAINCLASSE_API UChiappaETiraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UChiappaETiraComponent();
	
	UFUNCTION(BlueprintCallable)
	AActor* GetGrabbedObject();

	void PickUp();
	void Throw(float ForceApplied);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool GetIsHoldingObject();
private:
	FVector GetAttachLocation();
	
	FHitResult LookForActorsInRange();

	AActor* GrabbedObject = nullptr;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	float PickUpAnimTime = 0.f;
	float PickUpTime = 0.f;
	float PickUpCooldown = .8;
	UAttachMesh* Attach = nullptr;
	bool IsHoldingObject = false;
};
