// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInputComponent;
class ACaciaraInClasseCharacter;

UCLASS()
class CACIARAINCLASSE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
		virtual void BeginPlay() override;

private:
	UInputComponent * InputComponent = nullptr;
	void PickAndThrow();
	ACaciaraInClasseCharacter* OurPawn = nullptr;
};
