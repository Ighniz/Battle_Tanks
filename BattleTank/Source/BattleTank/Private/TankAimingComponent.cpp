// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; //TODO Should this really tick?

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Work-out difference between current barrel rotation, and AimDirection.
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;

	//Move the barrel the right amount this frame.
	Barrel->Elevate(5); //TODO remove magic number.

	//Given a max elevation speed, and the frame time.
}

void UTankAimingComponent::AimAt(FVector HitLocation, float TossSpeed)
{
	if (!Barrel) return;

	FVector OutTossVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutTossVelocity,
		StartLocation,
		HitLocation,
		TossSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);//Calculate The OutTossVelocity...

	auto Time = GetWorld()->GetTimeSeconds();
	if (bHaveAimSolution)
	{
		auto AimDirection = OutTossVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found."), Time);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found."), Time);
	}
}

