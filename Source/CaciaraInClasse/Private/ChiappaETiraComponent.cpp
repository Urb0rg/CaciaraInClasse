// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/ChiappaETiraComponent.h"
#include "Public/AttachMesh.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "CaciaraInClasse.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

// Sets default values for this component's properties
UChiappaETiraComponent::UChiappaETiraComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UChiappaETiraComponent::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();	
	Attach = GetOwner()->FindComponentByClass<UAttachMesh>();
}



// Called every frame
void UChiappaETiraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicsHandle->GrabbedComponent)
	{
		PhysicsHandle->SetTargetLocation(GetAttachLocation());
	}
}





FHitResult UChiappaETiraComponent::LookForActorsInRange()
{
	// create tarray for hit results
	FHitResult Hit;

	// start and end locations
	FVector SweepStart = GetOwner()->GetActorLocation();
	FVector SweepEnd = GetOwner()->GetActorLocation();

	// create a collision sphere
	FCollisionShape Sphere = FCollisionShape::MakeSphere(100.0f);
	FQuat Quat;
	FCollisionQueryParams SweepParameters(FName(TEXT("")), false, GetOwner());

	// draw collision sphere
	DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), Sphere.GetSphereRadius(), 50, FColor::Purple, true);

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



void UChiappaETiraComponent::PickUp()
{
	if (!PhysicsHandle) {
		UE_LOG(LogTemp, Warning, TEXT("No PhysicsHandle"))
			return;
	}
	
	auto Hit = LookForActorsInRange();
	auto Actor = Hit.GetActor();
	auto HitRoot = Hit.GetComponent();
	if (Actor)
	{
		

		if (HitRoot)
		{
			PhysicsHandle->GrabComponent
			(
				HitRoot,
				NAME_None, //
				Actor->GetActorLocation(),
				true //Allow rotation
			);


			UE_LOG(LogTemp, Warning, TEXT("Actor Attached"))

		}
			else { UE_LOG(LogTemp, Warning, TEXT("no  hit root")) }
	}
	else { UE_LOG(LogTemp, Warning, TEXT("no actor found")) }


}

void UChiappaETiraComponent::Throw(float ForceApplied)
{

	 UE_LOG(LogTemp, Warning, TEXT("THROW")) 
	/*if (!PhysicsHandle) { UE_LOG(LogTemp, Warning, TEXT("no physicshandle")) return; }*/
	if (!PhysicsHandle->GetGrabbedComponent()) { UE_LOG(LogTemp, Warning, TEXT("no attached component to throw")) return; }
	 auto AttachedComponent = PhysicsHandle->GetGrabbedComponent();
	 FVector ForceLocation = AttachedComponent->GetComponentLocation();
	 FVector ForceToApply = (GetOwner()->GetActorForwardVector()*ForceApplied);
	 AttachedComponent->AddForceAtLocation(ForceToApply, ForceLocation);
	 PhysicsHandle->ReleaseComponent();
	/*;
	//TODO fa crashare tutto!!
	

	
	*/
}





FVector UChiappaETiraComponent::GetAttachLocation()
{
	if (!Attach) { UE_LOG(LogTemp, Warning, TEXT("No AttachMesh")) return GetOwner()->GetActorLocation(); }

	return Attach->GetComponentLocation();

}