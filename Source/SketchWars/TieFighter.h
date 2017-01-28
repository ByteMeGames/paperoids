// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TieFighter.generated.h"

UCLASS()
class SKETCHWARS_API ATieFighter : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATieFighter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Sphere collision component.
	UPROPERTY(VisibleDefaultsOnly, Category = Sprite)
	class UPaperSpriteComponent* SpriteComponent;

	// Projectile movement component.
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Scoring")
	int32 ScoreValue;

	// Function that is called when the projectile hits something.
	UFUNCTION()
	void OnHit(class UPrimitiveComponent* HitComp, class AActor* Actor, class UPrimitiveComponent* Other, FVector Impulse, const FHitResult & HitResult);
};