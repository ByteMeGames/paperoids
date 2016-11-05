// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "SketchHUD.generated.h"

/**
 * 
 */
UCLASS()
class SKETCHWARS_API ASketchHUD : public AHUD {
	GENERATED_BODY()
		
public:
	// Primary draw call for the HUD.
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere)
	int32 Score;

	inline void SetScore(int32 Score) { this->Score = Score; }
	inline void IncrementScore(int32 Increment) { this->Score += Increment; }
};
