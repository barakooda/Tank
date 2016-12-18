// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
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

	TankAimComponent = CreateDefaultSubobject <UTankAimComponent>(FName("Aim Component Barak check"));
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

	//UE_LOG(LogTemp, Warning, TEXT("The test from blue print is: %s"), *PutSomeText);
}


void ATank::SetTurretReference(UTankTurret * TurretToSet, FString PutSomeText)
{

	TankAimComponent->SetTurretReference(TurretToSet);
	UE_LOG( LogTemp, Warning, TEXT("The test from turret is: %s"), *TurretToSet->GetName() );

	//TankAimComponent->SetBarrelReference(BarrelToset);

	
}


