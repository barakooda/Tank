// Fill out your copyright notice in the Description page of Project Settings.



#include "MyProject.h"
#include "Tank.h"
#include "TankAiController.h"
//Depend on movement component via path finding

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	CurrentPossesedTank = Cast<ATank>(GetPawn());
	CurrentPlayerController = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());


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

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentPossesedTank && CurrentPlayerController) 
	
	{

		MoveToActor(CurrentPlayerController, StopRadius);// check radius ditance unit //using path finding logic in tankmovemnet compenent

		FVector HitLocation = CurrentPlayerController->GetActorLocation();
		CurrentPossesedTank->AimAt(HitLocation);

		//fire every frame
		CurrentPossesedTank->fire();
	
	}

}



