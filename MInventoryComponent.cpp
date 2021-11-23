// Fill out your copyright notice in the Description page of Project Settings.


#include "MInventoryComponent.h"
#include "MGameGameModeBase.h"


// Sets default values for this component's properties
UMInventoryComponent::UMInventoryComponent()
{

}

// Called when the game starts
void UMInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UMInventoryComponent::AddItem(FName ItemID, AMItem* Item)
{
	AMGameGameModeBase* GameMode = Item->GetMyGameMode();
	bool bItemFound = false;
	FItem ItemFound = GameMode->FindItem(Item->ID, bItemFound);
	if (bItemFound == true)
	{
		//FItem NewItem;
		//NewItem.ID = Item->ID;
		//NewItem.Quantity = ItemFound.Quantity;
		//NewItem.MainParameters.Abbreviation = ItemFound.MainParameters.Abbreviation;
		//NewItem.MainParameters.EquipType = ItemFound.MainParameters.EquipType;
		//NewItem.MainParameters.InspectImage = ItemFound.MainParameters.InspectImage;
		//NewItem.MainParameters.InventoryImage = ItemFound.MainParameters.InventoryImage;
		//NewItem.MainParameters.IsUsable = ItemFound.MainParameters.IsUsable;
		//NewItem.MainParameters.Name = ItemFound.MainParameters.Name;
		//NewItem.MainParameters.SizeX = ItemFound.MainParameters.SizeX;
		//NewItem.MainParameters.SizeY = ItemFound.MainParameters.SizeY;
		//NewItem.MainParameters.StackSize = ItemFound.MainParameters.StackSize;
		//NewItem.MainParameters.UseType = ItemFound.MainParameters.UseType;
		//NewItem.Mesh.SkeletalMesh = ItemFound.Mesh.SkeletalMesh;
		//NewItem.Mesh.StaticMesh = ItemFound.Mesh.StaticMesh;

		FItem NewItem;
		NewItem.ID = ItemFound.ID;
		NewItem.Quantity = ItemFound.Quantity;
		NewItem.Abbreviation = ItemFound.Abbreviation;
		NewItem.EquipType = ItemFound.EquipType;
		NewItem.InspectImage = ItemFound.InspectImage;
		NewItem.InventoryImage = ItemFound.InventoryImage;
		NewItem.IsUsable = ItemFound.IsUsable;
		NewItem.Name = ItemFound.Name;
		NewItem.SizeX = ItemFound.SizeX;
		NewItem.SizeY = ItemFound.SizeY;
		NewItem.StackSize = ItemFound.StackSize;
		NewItem.UseType = ItemFound.UseType;
		NewItem.SkeletalMesh = ItemFound.SkeletalMesh;
		NewItem.StaticMesh = ItemFound.StaticMesh;
		
		Inventory.Add(NewItem);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor(255, 255, 255), "ADD ITEM");
	}
}