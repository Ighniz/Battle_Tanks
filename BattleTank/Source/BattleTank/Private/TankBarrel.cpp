// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine.h"



// -1 is max downward speed, and +1 is max up movement.
void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}
