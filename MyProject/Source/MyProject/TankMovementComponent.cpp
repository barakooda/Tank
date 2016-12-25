// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	UE_LOG(LogTemp, Warning, TEXT("The throttle of %s is : %f"), *(GetName()), Throw);
}




