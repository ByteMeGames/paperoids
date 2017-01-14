// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "TieFighter.h"
#include "PaperSpriteComponent.h"
#include "Bullet.h"
#include "SketchCharacter.h"


// Sets default values
ATieFighter::ATieFighter() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a sphere as a simple collision representation.
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	SpriteComponent->OnComponentHit.AddDynamic(this, &ATieFighter::OnHit);
	RootComponent = SpriteComponent;

	// Use this component to drive this projectile's movement.
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(SpriteComponent);
	ProjectileMovementComponent->InitialSpeed = 150.0f;
	ProjectileMovementComponent->MaxSpeed = 150.0f;
	ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void ATieFighter::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ATieFighter::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
}

void ATieFighter::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector Impulse, const FHitResult & HitResult) {
	if (OtherActor != this && OtherActor->IsA(ABullet::StaticClass())) {
		auto Player = Cast<ASketchCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
		auto Bullet = Cast<ABullet>(OtherActor);
		Player->IncrementScore(ScoreValue);
		Bullet->Destroy();
		this->Destroy();
	}
}