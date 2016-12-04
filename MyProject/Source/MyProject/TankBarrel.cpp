// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeDPS)
{
	RelativeDPS = FMath::Clamp(RelativeDPS, -1.f, 1.f);

	//move Barrel right amount this frame,clamp with max elevation and max speed.
	float ElevationChange = RelativeDPS * MaxDPS * GetWorld()->DeltaTimeSeconds; //speed 
	
	float RelavtiveNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	RelavtiveNewElevation = FMath::Clamp(RelavtiveNewElevation, MinElevationDegree, MaxElevationDegree);
	
	SetRelativeRotation ( FRotator(RelavtiveNewElevation, 0, 0) );
	
	//return;
}




