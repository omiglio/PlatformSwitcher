// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlatformSwitcherGameMode.h"
#include "PlatformSwitcherCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlatformSwitcherGameMode::APlatformSwitcherGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
