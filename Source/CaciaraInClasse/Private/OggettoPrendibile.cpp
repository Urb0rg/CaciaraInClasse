// Fill out your copyright notice in the Description page of Project Settings.

#include "OggettoPrendibile.h"


// Sets default values
AOggettoPrendibile::AOggettoPrendibile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOggettoPrendibile::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AOggettoPrendibile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
