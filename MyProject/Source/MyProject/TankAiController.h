// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAiController.generated.h"

//Forward Declaration

class UTankAimComponent;
/**
 * 
 */
UCLASS()

class MYPROJECT_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;


private:
	UTankAimComponent* TankAim = nullptr;

	//how close can the Ai takn get to the player.
	float StopRadius = 3;
	
};
