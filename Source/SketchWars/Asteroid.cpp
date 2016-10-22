// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "Asteroid.h"

#include "PaperSpriteComponent.h"


// Sets default values
AAsteroid::AAsteroid() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a sphere as a simple collision representation.
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->InitSphereRadius(15.0f);
	RootComponent = CollisionComponent;

	// Set up movement
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 100.0f;
	ProjectileMovementComponent->MaxSpeed = 300.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = false;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;
	RotationRate = -0.25f;

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	SpriteComponent->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AAsteroid::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );

	auto location = GetActorLocation();
	auto halfWidth = CollisionComponent->GetScaledSphereRadius();

	if (location.X + halfWidth < 0.0f) {
		location.X = 1024.0f + halfWidth;
	} else if (location.X > 1024.0f + halfWidth) {
		location.X = 0 - halfWidth;
	} else if (location.Z + halfWidth < 0.0f) {
		location.Z = 768.0f + halfWidth;
	} else if (location.Z > 768.0f + halfWidth) {
		location.Z = 0 - halfWidth;
	}
	SetActorLocation(location, false, nullptr, ETeleportType::TeleportPhysics);

	auto rotator = FRotator::MakeFromEuler(FVector(0.0f, RotationRate, 0.0f));
	SpriteComponent->AddWorldRotation(rotator);
}

