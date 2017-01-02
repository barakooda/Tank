// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankMovementComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimComponent.h"
#include "Tank.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// no need to protect pointers at construction phase

	TankAimComponent = CreateDefaultSubobject <UTankAimComponent>(FName("Aim Component Barak"));
	//TankMovementComponent = CreateDefaultSubobject <UTankMovementComponent>(FName("Movement Component Barak"));

	//TankAimComponent2 = CreateDefaultSubobject <UTankAimComponent>(FName("Aim Component Barak2"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
/*
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
*/

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
	{

		TankAimComponent->AimAt(HitLocation,LunchSpeed);
		
	}

void ATank::SetBarrelReference(UTankBarrel * BarrelToset,FString PutSomeText)
{
	
	TankAimComponent->SetBarrelReference(BarrelToset);
	Barrel = BarrelToset;
	//UE_LOG(LogTemp, Warning, TEXT("The test from blue print is: %s"), *PutSomeText);
}


void ATank::SetTurretReference(UTankTurret * TurretToSet, FString PutSomeText)
{

	TankAimComponent->SetTurretReference(TurretToSet);
	//UE_LOG( LogTemp, Warning, TEXT("The test from turret is: %s"), *TurretToSet->GetName() );

	//TankAimComponent->SetBarrelReference(BarrelToset);

	
}


void ATank::fire() 
{

	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	//UE_LOG(LogTemp, Warning, TEXT("Fire!!!"));
	
	if (Barrel && bIsReloaded)
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
