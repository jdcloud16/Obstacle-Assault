// This header file defines the AMovingPlatform class, which inherits from AActor
// It declares variables and functions used by the moving platform

#pragma once

// Includes Unreal Engine core types and macros
#include "CoreMinimal.h"
// Includes base class AActor to inherit from
#include "GameFramework/Actor.h"
// Generates boilerplate code for Unreal's reflection system
#include "MovingPlatform.generated.h"

// Declares that this class is an Unreal Engine actor
UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	// Macro required for Unreal reflection, serialization, and metadata
	GENERATED_BODY()
	
public:	
	// Constructor that sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Function called when the game starts or when the actor is spawned
	virtual void BeginPlay() override;

public:	
	// Function called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveDistance = 100;


	FVector StartLocation;

	
};
