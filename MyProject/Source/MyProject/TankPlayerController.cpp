// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin played"));
	
	CurrentPossesedTank = GetControlledTank();
	
	if (!CurrentPossesedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("no posseded tank") );
		 
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Current Possesed Tank is: %s"), *(CurrentPossesedTank->GetName()));
	}
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FString TankLocation = GetPawn()->GetActorLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("PlayerTank Location is : %s"), *(TankLocation));

	AimOnMarker();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::AimOnMarker()
{
	if (!CurrentPossesedTank) { return; }
	//start aim on the marker.
}
