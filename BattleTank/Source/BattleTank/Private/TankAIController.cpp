// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/Engine.h"


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// Move towards the player.
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm.

		// Aim towars the player.
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready.
		ControlledTank->Fire(); //TODO limit firing rate.
	}
}