// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OrbController.generated.h"

UCLASS()
class PLATFORMSWITCHER_API AOrbController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrbController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere) // What collides with player
	UShapeComponent* RootBox;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* 
		OtherActor, UPrimitiveComponent* OtherComponent, int32 
		OtherBodyIndex, bool bFromSweep, const FHitResult& 
		SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
