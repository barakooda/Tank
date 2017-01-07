// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimComponent.h"

//Forward Decleration

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false; //TODO should this really tick ?

	// ...
}




// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();
	TankAim = GetOwner()->FindComponentByClass<UTankAimComponent>();
	
}


// Called every frame
void UTankAimComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

}

void UTankAimComponent::AimLocation(FVector HitLocation)
{

	if (!ensure(TankAim)) { return; } //ensure
	AimAt(HitLocation, LunchSpeed);

}

void UTankAimComponent::AimAt(FVector HitLocation,float LunchSpeed)
{
	
	if ( !ensure(Barrel) ) { return; } //ensure
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
		0,
		0,
		false,
		ESuggestProjVelocityTraceOption::DoNotTrace
		);
////////////////////////////////////////////////////////		
	float Time = GetWorld()->GetTimeSeconds();
	if (bHaveAimSolution)

		

	{ 
		FVector AimDirection = OutLunchVelocity.GetSafeNormal();
		
		
		
		BarrelToAim(AimDirection);

		TurretToAim(AimDirection);

	}
	
	
}


void UTankAimComponent::InitialiseAim(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	if ( !ensure( BarrelToSet && TurretToSet ) ) { return; } // ensure
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}



void UTankAimComponent::BarrelToAim(FVector AimDirection)
{
	
	if (!ensure (Barrel) ) { return; } //ensure
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();

	FRotator DeltaRotator = AimRotator - BarrelRotator;
	
	

	Barrel->Elevate(DeltaRotator.Pitch); //TODO magic number

}

void UTankAimComponent::TurretToAim(FVector AimDirection) 
	{
	if (!ensure(Turret)) { return; } //ensure
	FRotator TurretRotator = Turret->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimRotator - TurretRotator;
	
	Turret->Rotate(DeltaRotator.Yaw);

	
	}




