// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interact.h"
#include "MItem.generated.h"

UCLASS()
class MGAME_API AMItem : public AActor, public IInteract
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMItem();

	UPROPERTY(VisibleAnywhere)
		USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SkeletalMeshComponent;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void Interact(AActor* Caller);
		virtual void Interact_Implementation(AActor* Caller) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactive")
		FName ID;

	UFUNCTION()
		FName GetName();
	
	UFUNCTION()
		void SetInfo();

	UFUNCTION()
		UWorld* GetItemWorld();

	UFUNCTION()
		AMGameGameModeBase* GetMyGameMode();

	UPROPERTY()
		class UMInventoryComponent* InventoryComponent;

};
