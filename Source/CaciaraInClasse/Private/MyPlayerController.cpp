// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "Components/InputComponent.h"
#include "ChiappaETiraComponent.h"
#include "CaciaraInClasseCharacter.h"


void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	OurPawn = Cast<ACaciaraInClasseCharacter>(GetPawn());
	InputComponent = GetPawn()->FindComponentByClass<UInputComponent>();
	
	if (InputComponent) 
	{ 
		InputComponent->BindAction("PickNThrow", IE_Pressed, this, &AMyPlayerController::PickAndThrow);
	}
	
}


void AMyPlayerController::PickAndThrow()
{
	UE_LOG(LogTemp, Warning, TEXT("pick & throw"))
		if (OurPawn->ChiappaETira->GetIsHoldingObject()) { OurPawn->Throw(); }
		else { OurPawn->PickUp(); }
}