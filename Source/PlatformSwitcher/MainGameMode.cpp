// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

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
