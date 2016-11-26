// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"



/**
 * 
 */
UCLASS()
class MYPROJECT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
void Elevate(float DPS); // Degree per second .
	
private:

};
