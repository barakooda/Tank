// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	CurrentPossesedTank = GetControlledTank();
	CurrentPlayerController = GetPlayerController();


	/////////////////////////////////////////Check if tank was possesed////////////////////////////////////////////////////////////////
	if (!CurrentPossesedTank)
	{
		UE_LOG(LogTemp,Warning,TEXT("No Tank Possed to Ai Controller"))
	}
	else 
	{
		FString PossesedTank = CurrentPossesedTank->GetName();
		
		/////////////////////////////////////////Check if playerController exist////////////////////////////////////////////////////////////////
		if (!CurrentPlayerController)
		{
			UE_LOG(LogTemp, Warning, TEXT("Ai Tank %s Cant Find Player Controller"), *PossesedTank )
		}
		else

		{
			FString CurrentPC = CurrentPlayerController->GetName();
			UE_LOG(LogTemp, Warning, TEXT("Ai Tank %s found PlayController:%s"), *PossesedTank, *CurrentPC)

		}
		
		
	}


}

ATank* ATankAiController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());

}

ATank* ATankAiController::GetPlayerController() const
{
	return Cast<ATank> (GetWorld()->GetFirstPlayerController()->GetPawn());
}


