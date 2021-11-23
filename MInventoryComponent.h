// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MDefinitions.h"
#include "MItem.h"
#include "Containers/Array.h"
#include "MInventoryComponent.generated.h"


UCLASS( ClassGroup=(Inventory), meta=(BlueprintSpawnableComponent) )
class MGAME_API UMInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMInventoryComponent();

	UFUNCTION(BlueprintCallable)
		void AddItem(FName ItemID, AMItem* Item);

	// Equipment inventory
	UPROPERTY(EditAnywhere)
		TArray<FItem> Inventory;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
