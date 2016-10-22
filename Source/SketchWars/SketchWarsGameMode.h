// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "SketchWarsGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SKETCHWARS_API ASketchWarsGameMode : public AGameMode {
	GENERATED_BODY()
	
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
};
