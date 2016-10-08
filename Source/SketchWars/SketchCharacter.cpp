// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "SketchCharacter.h"

// Sets default values
ASketchCharacter::ASketchCharacter() {
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	viewportSize = GetGameViewportSize();
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASketchCharacter::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ASketchCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto location = GetActorLocation();
	FVector bounds, origin;
	GetActorBounds(false, origin, bounds);
	auto halfWidth = (bounds.X / 2);
	auto halfHeight = (bounds.Z / 2);

	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, location.ToString());
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, viewportSize.ToString());
	if (location.X + halfWidth < 0.0f) {
		location.X = 1024.0f + halfWidth;
	} else if (location.X > 1024.0f + halfWidth) {
		location.X = 0 - halfWidth;
	} else if (location.Z + halfHeight < 0.0f) {
		location.Z = 768.0f + halfHeight;
	} else if (location.Z > 768.0f + halfHeight) {
		location.Z = 0 - halfHeight;
	}
	SetActorLocation(location, false, nullptr, ETeleportType::TeleportPhysics);
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

FVector2D ASketchCharacter::GetGameViewportSize() {
	FVector2D Result = FVector2D(1, 1);

	if (GEngine && GEngine->GameViewport) {
		GEngine->GameViewport->GetViewportSize( /*out*/Result);
	}

	return Result;
}