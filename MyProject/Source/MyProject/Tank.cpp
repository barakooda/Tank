// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Tank.h"



void ATank::BeginPlay()
{
	Super::BeginPlay();

	

}

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

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
