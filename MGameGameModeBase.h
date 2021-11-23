// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MDefinitions.h"
#include "MGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MGAME_API AMGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
///////////////////////// Inventory ////////////////////////////////
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item System")
		class UItemData* ItemDatabase;

public:

	AMGameGameModeBase();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item System")
		FItem FindItem(FName ItemID, bool& Success);

	FItem FindItem_Implementation(FName ItemID, bool& Success);


};
