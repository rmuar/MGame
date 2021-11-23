// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MDefinitions.generated.h"


UENUM(BlueprintType)
enum class EEquipType : uint8 {

	None				UMETA(DisplayName = "None"),
	Helmet				UMETA(DisplayName = "Helmet"),
	BodyArmor			UMETA(DisplayName = "BodyArmor"),
	ArmArmor			UMETA(DisplayName = "ArmArmor"),
	LegArmor			UMETA(DisplayName = "LegArmor"),
	BackPack			UMETA(DisplayName = "BackPack"),
	SafetyPack			UMETA(DisplayName = "SafetyPack"),
	TopClothing			UMETA(DisplayName = "TopClothing"),
	BottomClothing		UMETA(DisplayName = "BottomClothing"),
	Pockets				UMETA(DisplayName = "Pockets"),
	Gloves				UMETA(DisplayName = "Gloves"),
	Necklace			UMETA(DisplayName = "Necklace"),
	Ring				UMETA(DisplayName = "Ring"),
	Watch				UMETA(DisplayName = "Watch"),
	PrimaryWeapon		UMETA(DisplayName = "PrimaryWeapon"),
	SecondaryWeapon		UMETA(DisplayName = "SecondaryWeapon"),
	WeaponAttachment	UMETA(DisplayName = "WeaponAttachment"),
	MeleeWeapon			UMETA(DisplayName = "MeleeWeapon"),
	ThowableWeapon		UMETA(DisplayName = "ThowableWeapon"),
	Magazine			UMETA(DisplayName = "Magazine"),
	Technology			UMETA(DisplayName = "Technology"),
	Medicine			UMETA(DisplayName = "Medicine"),
	Money				UMETA(DisplayName = "Money"),
	BuildingMaterial	UMETA(DisplayName = "BuildingMaterial"),
	Key					UMETA(DisplayName = "Key"),
	BarterItem			UMETA(DisplayName = "BarterItem")
};

UENUM(BlueprintType)
enum class EUseType : uint8 {

	Countable			UMETA(DisplayName = "Countable"),
	CountableCantSlit	UMETA(DisplayName = "CountableCantSlit"),
	Infinity			UMETA(DisplayName = "Infinity"),

};

//USTRUCT(BlueprintType)
//struct FMainParameters
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere)
//		FString Name;
//
//	UPROPERTY(EditAnywhere)
//		FString Abbreviation;
//
//	UPROPERTY(EditAnywhere)
//		uint8 SizeX;
//
//	UPROPERTY(EditAnywhere)
//		uint8 SizeY;
//
//	UPROPERTY(EditAnywhere)
//		uint8 StackSize;
//
//	UPROPERTY(EditAnywhere)
//		UTexture2D* InventoryImage;
//
//	UPROPERTY(EditAnywhere)
//		UTexture2D* InspectImage;
//
//	UPROPERTY(EditAnywhere)
//		EEquipType EquipType;
//
//	UPROPERTY(EditAnywhere)
//		EUseType UseType;
//
//	UPROPERTY(EditAnywhere)
//		bool IsUsable;
//
//	FMainParameters()
//	{
//		Name = Name;
//		Abbreviation = Abbreviation;
//		SizeX = 1;
//		SizeY = 1;
//		StackSize = 1;
//		InventoryImage = nullptr;
//		InspectImage = nullptr;
//		EquipType = EEquipType::None;
//		UseType = EUseType::Countable;
//		IsUsable = 0;
//	}
//};

//USTRUCT(BlueprintType)
//struct FItemMeshes
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnywhere)
//		UStaticMesh* StaticMesh;
//
//	UPROPERTY(EditAnywhere)
//		USkeletalMesh* SkeletalMesh;
//
//	FItemMeshes()
//	{
//		StaticMesh = nullptr;
//		SkeletalMesh = nullptr;
//	}
//};

USTRUCT(BlueprintType)
struct FEquipFeatures
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FEquipParameters
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FModifiers
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		FName ID;

	UPROPERTY(EditAnywhere)
		uint8 Quantity;

	UPROPERTY(EditAnywhere)
		FString Name;

	UPROPERTY(EditAnywhere)
		FString Abbreviation;

	UPROPERTY(EditAnywhere)
		uint8 SizeX;

	UPROPERTY(EditAnywhere)
		uint8 SizeY;

	UPROPERTY(EditAnywhere)
		uint8 StackSize;

	UPROPERTY(EditAnywhere)
		UTexture2D* InventoryImage;

	UPROPERTY(EditAnywhere)
		UTexture2D* InspectImage;

	UPROPERTY(EditAnywhere)
		EEquipType EquipType;

	UPROPERTY(EditAnywhere)
		EUseType UseType;

	UPROPERTY(EditAnywhere)
		bool IsUsable;

	UPROPERTY(EditAnywhere)
		UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere)
		USkeletalMesh* SkeletalMesh;

	//UPROPERTY(EditAnywhere)
		//FMainParameters MainParameters;

	//UPROPERTY(EditAnywhere)
	//	FItemMeshes Mesh;

	FItem()
	{
		ID = "ItemID";
		Quantity = 0;
		Name = "Name";
		Abbreviation = "Abbreviation";
		SizeX = 1;
		SizeY = 1;
		StackSize = 1;
		InventoryImage = nullptr;
		InspectImage = nullptr;
		EquipType = EEquipType::None;
		UseType = EUseType::Countable;
		IsUsable = 0;
		StaticMesh = nullptr;
		SkeletalMesh = nullptr;
	}
};

UCLASS(BlueprintType)
class UItemData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Data")
		TArray<FItem> Data;

};

//class MGAME_API UMDefinitions
//{
//	//GENERATED_BODY()
//public:
//	MDefinitions();
//	~MDefinitions();
//};
