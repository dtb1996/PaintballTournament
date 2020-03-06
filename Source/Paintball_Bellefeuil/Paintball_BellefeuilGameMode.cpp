// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Paintball_BellefeuilGameMode.h"
#include "Paintball_BellefeuilHUD.h"
#include "Paintball_BellefeuilCharacter.h"
#include "UObject/ConstructorHelpers.h"

APaintball_BellefeuilGameMode::APaintball_BellefeuilGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APaintball_BellefeuilHUD::StaticClass();
}
