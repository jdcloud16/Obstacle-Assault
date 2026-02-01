// This source file defines the behavior of AMovingPlatform class

#include "MovingPlatform.h"

// Constructor that sets default values
AMovingPlatform::AMovingPlatform()
{
	// Allows this actor to call Tick() every frame
	// Can be turned off for better performance if ticking isn't needed
	PrimaryActorTick.bCanEverTick = true;
}

// Function called when the game starts or the actor is spawned
void AMovingPlatform::BeginPlay()
{
	// Calls the parent class's BeginPlay to ensure proper initialization
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);
}

// Function called every frame with DeltaTime (time since last frame)
void AMovingPlatform::Tick(float DeltaTime)
{
	// Calls the parent class's Tick to maintain base functionality
	Super::Tick(DeltaTime);

	MovePlatform();

	// Move platform forwards
		// Get current location
	FVector CurrentLocation = GetActorLocation();

		// Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// Set the location
	SetActorLocation(CurrentLocation);

	// Send platform back if gone too far
		// Check how far we've moved
		// initalized here to become local variable
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

		// Reverse direction of motion if gone too far
	if(DistanceMoved > MoveDistance)
	{
		float OverShoot = DistanceMoved - MoveDistance;
		FString Name = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s Platform overshot by %f"), *Name, OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}

}

// hello