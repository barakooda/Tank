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
		
		//UE_LOG(LogTemp, Warning, TEXT("Aim Direction:%s"), *AimDirection.ToString());
		
		BarrelToAim(AimDirection);

		TurretToAim(AimDirection);

		//UE_LOG(LogTemp, Warning, TEXT("Aim Vector : %s"), *AimDirection.ToString());

	}
	
	else 
	{
		//UE_LOG(LogTemp, Warning, TEXT("No Aim Solve Found at time : %f"), Time);
	}
	
	
	
}

	
void UTankAimComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimComponent::SetTurretReference(UTankTurret* TurretToSet) 
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
	//UE_LOG(LogTemp, Warning, TEXT("Turrret works"));
}

void UTankAimComponent::BarrelToAim(FVector AimDirection)
{
	

	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();

	FRotator DeltaRotator = AimRotator - BarrelRotator;
	
	//UE_LOG(LogTemp, Warning, TEXT("rotator diffrence: %s"), *DeltaRotator.ToString());
	

	Barrel->Elevate(DeltaRotator.Pitch); //TODO magic number

}

void UTankAimComponent::TurretToAim(FVector AimDirection) 
	{

	FRotator TurretRotator = Turret->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimRotator - TurretRotator;
	
	Turret->Rotate(DeltaRotator.Yaw);

	//UE_LOG( LogTemp, Warning, TEXT("Delta Turret Rotator %s" ), *DeltaRotator.ToString() );
	
	}




