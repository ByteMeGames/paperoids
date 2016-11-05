// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "SketchHUD.h"

void ASketchHUD::DrawHUD()
{
	Super::DrawHUD();

	FNumberFormattingOptions NumberFormat;
	NumberFormat.MinimumIntegralDigits = 5;
	NumberFormat.MaximumFractionalDigits = 0;
	NumberFormat.SetUseGrouping(false);

	FCanvasTextItem TextItem(FVector2D(10.0f, 10.0f), FText::AsNumber(Score, &NumberFormat), GEngine->GetLargeFont(), FLinearColor::Red);
	Canvas->DrawItem(TextItem);
}
