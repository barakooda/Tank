// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProject.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimComponent.h"

//Forward Decleration

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true; //TODO should this really tick ?
	
	
	// ...
}
void UTankAimComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)

{
	//UE_LOG(LogTemp, Warning, TEXT("Tick Works : %f"), DeltaTime);

	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) < ReloadTime;
	
	
	if (bIsReloaded) 
	{
		FiringState = EFiringStatus::Reload;
	}
	else if ( IsBarrelMoving() )
	{

		FiringState = EFiringStatus::Aim;
	}
	else
	{
		FiringState = EFiringStatus::Locked;
	}

}



// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();
	TankAim = GetOwner()->FindComponentByClass<UTankAimComponent>();
	
	//so the first sire will be after 3 second.
	LastFireTime = FPlatformTime::Seconds();
}


// Called every frame
/*
void UTankAimComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

}
*/
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
		AimDirection = OutLunchVelocity.GetSafeNormal();
		
		
		
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
		if (FMath::Abs(DeltaRotator.Yaw) < 180)
		{ 
			Turret->Rotate(DeltaRotator.Yaw);
		}
		else

		{
			Turret->Rotate(-DeltaRotator.Yaw);
		}

	
	}

void UTankAimComponent::fire()

{

	
	//UE_LOG(LogTemp, Warning, TEXT("Fire!!!"));

	if ( (FiringState != EFiringStatus::Reload) )
	{
		//spwan projectile on socket of barrel.
		FVector Location = Barrel->GetSocketLocation("BarrelEnd");
		FRotator Rotation = Barrel->GetSocketRotation("BarrelEnd");
		//UE_LOG( LogTemp, Warning, TEXT("Fire!!! location : %s "), *Location.ToString() );

		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Location, Rotation);

		Projectile->LunchProjectile(LunchSpeed);
		LastFireTime = FPlatformTime::Seconds();

	}
}

bool UTankAimComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }
	
	return !AimDirection.Equals(Barrel->GetForwardVector(), 0.2);
	
}




