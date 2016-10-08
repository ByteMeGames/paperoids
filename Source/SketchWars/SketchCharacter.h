// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "SketchCharacter.generated.h"

/**
 * 
 */
UCLASS()
class SKETCHWARS_API ASketchCharacter : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	ASketchCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION()
	void TurnRight(float Value);
};
