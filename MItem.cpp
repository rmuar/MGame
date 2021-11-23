// Fill out your copyright notice in the Description page of Project Settings.


#include "MItem.h"
#include "MDefinitions.h"
#include "MInventoryComponent.h"
#include "MGameGameModeBase.h"


#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AMItem::AMItem()
{

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	SceneComponent->SetupAttachment(StaticMeshComponent);
	SceneComponent->SetupAttachment(SkeletalMeshComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));

}

// Called when the game starts or when spawned
void AMItem::BeginPlay()
{
	Super::BeginPlay();

	SetInfo();
}

UWorld* AMItem::GetItemWorld()
{
	return this->GetWorld();
}

AMGameGameModeBase* AMItem::GetMyGameMode()
{
	return Cast<AMGameGameModeBase>(GetItemWorld()->GetAuthGameMode());
}

FName AMItem::GetName()
{
	return ID;
}

void AMItem::SetInfo()
{
	AMGameGameModeBase* GameMode = GetMyGameMode();
	bool Found = false;
	FItem ItemFound = GameMode->FindItem(ID, Found);
	if (Found)
	{
		SkeletalMeshComponent->SetSkeletalMesh(ItemFound.SkeletalMesh);
		StaticMeshComponent->SetStaticMesh(ItemFound.StaticMesh);

		//SkeletalMeshComponent->SetSkeletalMesh(ItemFound.Mesh.SkeletalMesh);
		//StaticMeshComponent->SetStaticMesh(ItemFound.Mesh.StaticMesh);
	}
}

void AMItem::Interact_Implementation(AActor* Caller)
{
	InventoryComponent->AddItem(ID, this);
}

