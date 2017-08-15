// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float) override;
	ATank* GetControlledTank() const;

	//Start the tank moving the barrel so that sa shot would it where the crosshair intersect the world.
	void AimTowardsCrosshair();
};
