// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "SketchCharacter.h"

// Sets default values
ASketchCharacter::ASketchCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASketchCharacter::BeginPlay() {
	Super::BeginPlay();

	if (GEngine) {
		// Put up a debug message for five seconds. The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
	}
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
}

void ASketchCharacter::TurnRight(float value) {
	APlayerController* const PC = CastChecked<APlayerController>(Controller);
	auto Transform = GetActorTransform();
	auto rotator = FRotator::MakeFromEuler(FVector(0.0f, value*5.0f, 0.0f));
	Transform.ConcatenateRotation(rotator.Quaternion());
	SetActorTransform(FTransform(Transform));
}