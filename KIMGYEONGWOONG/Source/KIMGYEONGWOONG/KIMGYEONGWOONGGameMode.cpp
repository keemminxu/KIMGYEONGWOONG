// Copyright Epic Games, Inc. All Rights Reserved.

#include "KIMGYEONGWOONGGameMode.h"
#include "KIMGYEONGWOONGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKIMGYEONGWOONGGameMode::AKIMGYEONGWOONGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
