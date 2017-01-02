// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

//Forward declaration 

class UTankTrack;

/**
 Resposible for driving the the tank tracks.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYPROJECT_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
	
public :


	UFUNCTION(BlueprintCallable, Category = TankMovement)
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable,Category = TankMovement)
	void IntendMoveForward (float Throw);

	UFUNCTION(BluePrintCallable, Category = TankMovement)
	void IntendRotateRight(float Throw);
	
	//Check best protection.
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;

};
