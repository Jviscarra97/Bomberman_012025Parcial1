// Copyright Epic Games, Inc. All Rights Reserved.

#include "Bomberman_012025GameMode.h"
#include "Bomberman_012025Character.h"
#include "UObject/ConstructorHelpers.h"

ABomberman_012025GameMode::ABomberman_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
