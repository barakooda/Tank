// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeDPS)
{
	RelativeDPS = FMath::Clamp(RelativeDPS, -1.f, 1.f);
	//RelativeDPS = FMath::Clamp(RelativeDPS, -1.0, +1.0);
	//RelativeDPS = FMath::Clamp<int>(RelativeDPS, -1, +1);
	//RelativeDPS=FMath::Clamp<float>(RelativeDPS, -1, +1);

	//move Barrel right amount this frame,clamp with max elevation and max speed.
	float ElevationChange = RelativeDPS * MaxDPS * GetWorld()->DeltaTimeSeconds; //speed 
	
	float RelavtiveNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	RelavtiveNewElevation = FMath::Clamp(RelavtiveNewElevation, MinElevationDegree, MaxElevationDegree);
	
	SetRelativeRotation ( FRotator(RelavtiveNewElevation, 0, 0) );
	//UE_LOG(LogTemp, Warning, TEXT("check barrel lift : %f"), RelativeDPS);
	//return;
}




