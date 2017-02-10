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

protected :
	//how close can the Ai takn get to the player.

	UPROPERTY (EditAnywhere,Category = "Setup") //Todo Consider editdeafult
	float StopRadius = 6000;

private:
	UTankAimComponent* TankAim = nullptr;

	
	
};
