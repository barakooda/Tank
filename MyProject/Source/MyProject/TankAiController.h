// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAiController.generated.h"

class ATank;
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

	//ATank* GetControlledTank() const;

	//ATank* GetPlayerController() const;

private:
	ATank* CurrentPossesedTank = nullptr;
	ATank* CurrentPlayerController = nullptr;

	//how close can the Ai takn get to the player.
	float StopRadius = 3;
	
};
