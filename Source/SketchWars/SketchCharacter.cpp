// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "SketchCharacter.h"

// Sets default values
ASketchCharacter::ASketchCharacter():
	isAccelerating(false) {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASketchCharacter::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ASketchCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASketchCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent) {
	Super::SetupPlayerInputComponent(InputComponent);

	// Set up "movement" bindings.
	InputComponent->BindAxis("TurnRight", this, &ASketchCharacter::TurnRight);
	InputComponent->BindAxis("Accelerate", this, &ASketchCharacter::MoveUp);
}

void ASketchCharacter::TurnRight(float val) {
	auto localTransform = GetActorTransform();
	auto rotator = FRotator::MakeFromEuler(FVector(0.0f, val*-5.0f, 0.0f));
	localTransform.ConcatenateRotation(rotator.Quaternion());
	SetActorTransform(FTransform(localTransform));
}

void ASketchCharacter::MoveUp(float val) {
	AddMovementInput(GetActorUpVector(), val);
}