// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"



/**
 * 
 */
UCLASS(meta = ( BlueprintSpawnableComponent),hidecategories = ("Collision","Lighting","Materials","Transform","Rendering") )
class MYPROJECT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
void Elevate(float RelativeDPS); // Degree per second .
	
private:
	UPROPERTY(EditAnywhere,Category = Setup)
	float MaxDPS = 5;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegree = 35;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegree = 0;

};
