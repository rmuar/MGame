// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interact.h"
#include "Camera/CameraComponent.h"
#include "MInventoryComponent.h"
#include "MCharacter.generated.h"



UCLASS()
class MGAME_API AMCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMCharacter();

	/** Pawn mesh: 1st person view */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* MCharacterMesh;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* MCameraComponent;

	UPROPERTY(VisibleAnywhere, Category = Inventory)
		UMInventoryComponent* InventoryComponent;

	/** Function to check for the closest Interactable in sight and in range. */
	UFUNCTION()
	FHitResult CheckInteract();

	UFUNCTION()
	void OnInteract();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles strafing movement, left and right */
	void MoveRight(float Val);

public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetCharacterMesh() const { return MCharacterMesh; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return MCameraComponent; }
	/** Returns InventoryComponent subobject **/
	//FORCEINLINE class UMInventoryComponent* GetInventoryComponent() const { return MInventoryComponent; }

};
