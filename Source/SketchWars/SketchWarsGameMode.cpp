// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "SketchWarsGameMode.h"

#include "Asteroid.h"

void ASketchWarsGameMode::BeginPlay() {
	Super::BeginPlay();
}

void ASketchWarsGameMode::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAsteroid::StaticClass(), FoundActors);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::FromInt(FoundActors.Num()));
}