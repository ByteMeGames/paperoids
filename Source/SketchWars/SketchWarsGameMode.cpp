// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "SketchWarsGameMode.h"

#include "Asteroid.h"

void ASketchWarsGameMode::BeginPlay() {
	Super::BeginPlay();
}

void ASketchWarsGameMode::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	UWorld* World = GetWorld();
	
	if (AsteroidClass && World) {
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(World, AAsteroid::StaticClass(), FoundActors);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::FromInt(FoundActors.Num()));

		TArray<AActor*> FoundSpawns;
		UGameplayStatics::GetAllActorsOfClass(World, ATargetPoint::StaticClass(), FoundSpawns);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::FromInt(FoundSpawns.Num()));

		if (FoundActors.Num() <= 4) {
			int32 index = FMath::RandRange(0, FoundSpawns.Num() - 1);
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;

			AActor* Spawn = FoundSpawns[index];
			World->SpawnActor<AAsteroid>(AsteroidClass, Spawn->GetActorLocation() , Spawn->GetActorRotation(), SpawnParams);
		}
	}
}