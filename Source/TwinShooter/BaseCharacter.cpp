// Fill out your copyright notice in the Description page of Project Settings.

#include "TwinShooter.h"
#include "BaseCharacter.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

// Implement Calculate Health
void ABaseCharacter::CalculateHealth(float Delta) {

	// We increase the Health Parameter passed as parameter
	Health += Delta;
	// After that we call the function CalculateDead
	CalculateDead();
}

// Implement Calculate Dead
void ABaseCharacter::CalculateDead() {

	if (Health <= 0) 
		isDead = true;
	else 
		isDead = false;
}

// Implement PostEditChange Property
#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) {

	isDead = false;
	Health = 100;
	
	// Call the super method
	Super::PostEditChangeProperty(PropertyChangedEvent);

	// Check if any changes kill the character
	CalculateDead();
}
#endif


