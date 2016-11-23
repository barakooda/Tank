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
	
	//FString TankLocation = GetPawn()->GetActorLocation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerTank Location is : %s"), *(TankLocation));
	
	AimOnMarker();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::AimOnMarker()
{
	if (!CurrentPossesedTank) { return; }
	
	FVector HitLocation = FVector(1.0); //Out parameter

	if (GetSightRayHitLocation(HitLocation))
		{

		CurrentPossesedTank->AimAt(HitLocation);

		}

	

}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{

	int32 SizeX = 0;
	int32 SizeY = 0;
	GetViewportSize(SizeX, SizeY);

	FVector2D ScreenLocation = FVector2D(SizeX * MarkXLocation, SizeY * MarkYLocation);
	FVector LookDirection;
	
	if ( GetLookDirection(ScreenLocation,LookDirection ) )
	{

		
		if (GetLookVectorHitLocation(LookDirection, HitLocation)) 
		{
			
			
			return true;
		}


		


		
	}
	
	//HitLocation = FVector(1.0);
	return false;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const 
{
	FVector WorldLocation; //discard

	return DeprojectScreenPositionToWorld
		(
			ScreenLocation.X,
			ScreenLocation.Y,
			WorldLocation,
			LookDirection 
		);
	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector &LookDirection,FVector &HitLocation) const
{
	FHitResult OutHit;
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + LookDirection * LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel
	(
		OutHit,
		Start,
		End,
		ECollisionChannel::ECC_Visibility)
		) 
	{
		HitLocation = OutHit.Location;
		
		return true;
	}
	else 
	{
		HitLocation = FVector(0);
		return true;
	}
	
}
