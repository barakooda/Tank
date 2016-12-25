// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Lighting", "Materials", "Transform", "Rendering" ))// "Collision"))
class MYPROJECT_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeDPS);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDPS = 5;

};
