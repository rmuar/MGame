// Fill out your copyright notice in the Description page of Project Settings.


#include "MCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetSystemLibrary.h"

#include "MGameGameModeBase.h"
#include "MItem.h"
#include "DrawDebugHelpers.h"


// Sets default values
AMCharacter::AMCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Create a CameraComponent	
	MCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	MCameraComponent->SetupAttachment(GetCapsuleComponent());
	MCameraComponent->SetRelativeLocation(FVector(0, 0, 64.f)); // Position the camera
	MCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	MCharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	MCharacterMesh->SetupAttachment(MCameraComponent);	// Attach mesh to FirstPersonCameraComponent

	InventoryComponent = CreateDefaultSubobject<UMInventoryComponent>(TEXT("InventoryComponent"));
	
}

// Called when the game starts or when spawned
void AMCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void AMCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AMCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMCharacter::OnInteract);


}

void AMCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// Add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AMCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// Add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

FHitResult AMCharacter::CheckInteract()
{
	FVector StartLocation = GetActorLocation(); //your location 
	FVector EndLocation = StartLocation + (MCameraComponent->GetForwardVector() * 500.f); //get forward dir
	FHitResult Hit;
	FCollisionQueryParams ColParms; //ignor stuff
	ColParms.AddIgnoredActor(this);//ignor hitting self

	GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECC_Visibility, ColParms);//ECC_WorldDynamic will only hit Actors, ECC_Visibility is everything

	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, false, 5.f, ECC_WorldStatic, 1.f);

	return Hit;
}

void AMCharacter::OnInteract()
{
	bool bisItemHit = UKismetSystemLibrary::DoesImplementInterface(CheckInteract().GetActor(), UInteract::StaticClass());

	if (bisItemHit)
	{
		UObject* InteractObject = CheckInteract().GetActor();
		IInteract::Execute_Interact(InteractObject, this);
	}
}