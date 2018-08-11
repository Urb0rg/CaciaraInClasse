// Fill out your copyright notice in the Description page of Project Settings.

#include "CICAIController.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"



FHitResult ACICAIController::LookForActorsInRange()
{
	// create tarray for hit results
	FHitResult Hit;
	 UE_LOG(LogTemp, Warning, TEXT("LFAIR")) 
	// start and end locations
		 if (!GetPawn()) { UE_LOG(LogTemp, Warning, TEXT("no pawn possessed by AIController")) return Hit; }
	FVector SweepStart = GetPawn()->GetActorLocation();
	FVector SweepEnd = GetPawn()->GetActorLocation();

	// create a collision sphere
	FCollisionShape Sphere = FCollisionShape::MakeSphere(1500.0f);
	FQuat Quat;
	FCollisionQueryParams SweepParameters(FName(TEXT("")), false, GetOwner());

	// draw collision sphere
	DrawDebugSphere(GetWorld(), GetPawn()->GetActorLocation(), Sphere.GetSphereRadius(), 50, FColor::Purple, true);

	// check if something got hit in the sweep
	GetWorld()->SweepSingleByObjectType
	(
		Hit,
		SweepStart,
		SweepEnd,
		Quat,
		ECC_PhysicsBody,
		Sphere,
		SweepParameters
	);

	return  Hit;
}