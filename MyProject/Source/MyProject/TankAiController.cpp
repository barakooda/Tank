// Fill out your copyright notice in the Description page of Project Settings.



#include "MyProject.h"
#include "TankAimComponent.h"
#include "TankAiController.h"
//Depend on movement component via path finding

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	auto CurrentPossesedTank = GetPawn();
	auto CurrentPlayerController = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (ensure(CurrentPossesedTank))

	{
		TankAim = CurrentPossesedTank->FindComponentByClass<UTankAimComponent>();

	}


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

	auto CurrentPossesedTank = GetPawn();
	auto CurrentPlayerController = GetWorld()->GetFirstPlayerController()->GetPawn();


	if (ensure(CurrentPossesedTank && CurrentPlayerController) )
	
	{
		TankAim = CurrentPossesedTank->FindComponentByClass<UTankAimComponent>();

		MoveToActor(CurrentPlayerController, StopRadius);// check radius ditance unit //using path finding logic in tankmovemnet compenent

		FVector HitLocation = CurrentPlayerController->GetActorLocation();
		TankAim->AimLocation(HitLocation);

		//fire every frame
		TankAim->fire(); //TODO add fire option
	
	}

}



