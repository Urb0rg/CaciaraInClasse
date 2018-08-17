// Fill out your copyright notice in the Description page of Project Settings.

#include "CICAIController.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "ChiappaETiraComponent.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

void ACICAIController::BeginPlay()
{
	Super::BeginPlay();

	Chiappa = GetPawn()->FindComponentByClass<UChiappaETiraComponent>();
}

FHitResult ACICAIController::LookForActorsInRange()
{
	// create tarray for hit results
	TArray<FHitResult> Hit;
	 UE_LOG(LogTemp, Warning, TEXT("LFAIR")) 
	// start and end locations
		 if (!GetPawn()) { UE_LOG(LogTemp, Warning, TEXT("no pawn possessed by AIController")) return Hit[0]; }
	FVector SweepStart = GetPawn()->GetActorLocation();
	FVector SweepEnd = GetPawn()->GetActorLocation();

	// create a collision sphere
	FCollisionShape Sphere = FCollisionShape::MakeSphere(1500.0f);
	FQuat Quat;
	FCollisionQueryParams SweepParameters(FName(TEXT("")), false, GetOwner());

	// draw collision sphere
	DrawDebugSphere(GetWorld(), GetPawn()->GetActorLocation(), Sphere.GetSphereRadius(), 50, FColor::Purple, true);

	// check if something got hit in the sweep
	GetWorld()->SweepMultiByObjectType
	(
		Hit,
		SweepStart,
		SweepEnd,
		Quat,
		ECC_PhysicsBody,
		Sphere,
		SweepParameters
	);
	return GetRandomActorInRange(Hit);
}

AActor* ACICAIController::GetActorToPick()//TODO make a sweep multy y object type and select a random object to pick
{
	auto Hit = LookForActorsInRange();
	auto Actor = Hit.GetActor();
	return Actor;
}
void ACICAIController::PickUp()
{
	if (!Chiappa) { UE_LOG(LogTemp, Warning, TEXT("no chiappa su ai controller while picking up"))  return; }

	Chiappa->PickUp();
	Grabbing = true;
}

void ACICAIController::Throw()
{
	if (!Chiappa) { UE_LOG(LogTemp, Warning, TEXT("no chiappa su ai controller ehile throwing object"))  return; }

	Chiappa->Throw(ThrowSpeed);
	Grabbing = false;
}

AActor* ACICAIController::GetGrabbedObject()
{
	if (!Chiappa) { UE_LOG(LogTemp, Warning, TEXT("no chiappa su ai controller while getting grabbed object"))  return nullptr; }
	return Chiappa->GetGrabbedObject();
}

FHitResult ACICAIController::GetRandomActorInRange(TArray<FHitResult> HitArray)
{
	auto ArrayLength = HitArray.Num();
	int RandIndex = rand() % ArrayLength;
	FHitResult RandomActorInRange = HitArray[RandIndex];
	return RandomActorInRange;
}