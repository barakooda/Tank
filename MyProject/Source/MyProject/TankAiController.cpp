// Fill out your copyright notice in the Description page of Project Settings.



#include "MyProject.h"
#include "TankAimComponent.h"
#include "TankAiController.h"
#include "Tank.h" //we can implement OnDeath
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
void ATankAiController::SetPawn(APawn * InPawn)

{
	Super::SetPawn(InPawn);
	if (InPawn) 
	{
		 
		auto PossedTank = Cast<ATank>(InPawn);

		if (!ensure(PossedTank)) { return; }

		//subscribe our local method to the tank death
		PossedTank->OnDeath.AddUniqueDynamic(this,&ATankAiController::OnPossedTankDeath);
	}
}

void ATankAiController::OnPossedTankDeath()
{
	UE_LOG(LogTemp,Warning,TEXT("recvied"));
	
	if (!GetPawn()) { return; }
	GetPawn() -> DetachFromControllerPendingDestroy();
	
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

		//TODO if aimng or locked then fire.
		if (TankAim->GetFireingState() == EFiringStatus::Locked)
			{
				TankAim->fire(); //TODO add fire option
			}
	}

}



