// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject.h"
#include "TankBarrel.h"
#include "TankAimComponent.h"

//Forward Decleration

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimComponent::AimAt(FVector HitLocation,float LunchSpeed)
{
	//FString TankName = GetOwner()->GetName();
	//FVector BarrelLocation = Barrel->GetComponentLocation();
	
	if (!Barrel) { return; }
	FVector OutLunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("BarrelEnd"));
////////////////////////////////////////////////////////////////	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLunchVelocity,
		StartLocation,
		HitLocation,
		LunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace);
////////////////////////////////////////////////////////		

	if (bHaveAimSolution)

	{ 
		FVector AimDirection = OutLunchVelocity.GetSafeNormal();

		//UE_LOG(LogTemp, Warning, TEXT("Aim Direction:%s"), *AimDirection.ToString());
		BarrelToAim(AimDirection);

	}
	
	
	
}

	
void UTankAimComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimComponent::BarrelToAim(FVector AimDirection)
{
	
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();

	FRotator DeltaRotator = AimRotator = BarrelRotator;

	

	Barrel->Elevate(5); //TODO magic number

}
