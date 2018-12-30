// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "OggettoPrendibile.generated.h"

UCLASS()
class CACIARAINCLASSE_API AOggettoPrendibile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOggettoPrendibile();


	UPROPERTY(BlueprintReadOnly)
	bool IsTaken = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class ACaciaraInClasseCharacter* Character;

private:

	
};
