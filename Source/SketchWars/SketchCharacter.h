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

private:
	FTransform InitialTransform;
	
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
	void TurnRight(float val);

	UFUNCTION()
	void MoveUp(float val);

	UFUNCTION()
	void Fire();

	// Projectile class to spawn.
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABullet> ProjectileClass;

	UPROPERTY(VisibleAnywhere, Category = "Lives")
	int32 NumLives;

	UFUNCTION()
	void OnHit(class UPrimitiveComponent* HitComp, class AActor* Actor, class UPrimitiveComponent* Other, FVector Impulse, const FHitResult & HitResult);

	UFUNCTION()
	void Respawn();
};
