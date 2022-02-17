// Fill out your copyright notice in the Description page of Project Settings.

#include "GameWidget.h"
#include "MainGameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	ChangeMenuWidget(StartingWidgetClass);

	((UGameWidget*)CurrentWidget)->Load();

	GetWorld()->GetFirstPlayerController()->InputComponent->
		BindAction("Switch", IE_Pressed, this, &AMainGameMode::
		OnSwitch);
}

void AMainGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainGameMode::OnSwitch()
{
	if (Switched)
	{
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter
			(GetWorld(), 0)->GetActorLocation();
		NewLocation.X = 1200.0f;
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->
			SetActorLocation(NewLocation);
	}
	else
	{
		FVector NewLocation = UGameplayStatics::GetPlayerCharacter
		(GetWorld(), 0)->GetActorLocation();
		NewLocation.X = 58.272f;
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->
			SetActorLocation(NewLocation);
	}

	Switched = !Switched;
}

void AMainGameMode::OnGameOver(bool win)
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void AMainGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget>
	NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(),
			NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}