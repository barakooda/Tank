// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeDPS)
{
	RelativeDPS = FMath::Clamp(RelativeDPS, -1.f, 1.f);

	//move Barrel right amount this frame,clamp with max elevation and max speed.
	float RotationChange = RelativeDPS * MaxDPS * GetWorld()->DeltaTimeSeconds; //speed 

	float RelavtiveNewRotation = RelativeRotation.Yaw + RotationChange;

	//RelavtiveNewRotation = FMath::Clamp(RelavtiveNewRotation, MinElevationDegree, MaxElevationDegree);

	SetRelativeRotation(FRotator(0, 0, RelavtiveNewRotation));
}


