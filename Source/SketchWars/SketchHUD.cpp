// Fill out your copyright notice in the Description page of Project Settings.

#include "SketchWars.h"
#include "SketchHUD.h"

#include "SketchCharacter.h"

void ASketchHUD::DrawHUD()
{
	Super::DrawHUD();

	FNumberFormattingOptions ScoreFormat;
	ScoreFormat.MinimumIntegralDigits = 5;
	ScoreFormat.MaximumFractionalDigits = 0;
	ScoreFormat.SetUseGrouping(false);

	FCanvasTextItem ScoreItem(FVector2D(10.0f, 10.0f), FText::AsNumber(Score, &ScoreFormat), GEngine->GetLargeFont(), FLinearColor::Red);
	Canvas->DrawItem(ScoreItem);

	FNumberFormattingOptions LivesFormat;
	LivesFormat.MinimumIntegralDigits = 1;
	LivesFormat.MaximumFractionalDigits = 0;
	LivesFormat.SetUseGrouping(false);

	ASketchCharacter* Player = Cast<ASketchCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	FCanvasTextItem LivesItem(FVector2D(Canvas->ClipX - 20.0f, 10.0f), FText::AsNumber(Player->NumLives, &LivesFormat), GEngine->GetLargeFont(), FLinearColor::Red);
	Canvas->DrawItem(LivesItem);
}
