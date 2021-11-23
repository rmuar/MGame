// Copyright Epic Games, Inc. All Rights Reserved.


#include "MGameGameModeBase.h"
#include "MCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AMGameGameModeBase::AMGameGameModeBase()
{

}

FItem AMGameGameModeBase::FindItem_Implementation(FName ItemID, bool& Success)
{
	Success = false;

	FItem Item;
	if (ItemDatabase == nullptr) { return Item; }

	for (int i = 0; i < ItemDatabase->Data.Num(); i++)
	{
		if (ItemDatabase->Data[i].ID == ItemID)
		{
			Success = true;
			return ItemDatabase->Data[i];
		}
	}
	return Item;
}