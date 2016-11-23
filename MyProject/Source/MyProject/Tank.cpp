// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Tank.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// no need to protect pointers at construction phase

	TankAimComponent = CreateDefaultSubobject <UTankAimComponent>(FName("Aim Component Barak"));
	//TankAimComponent2 = CreateDefaultSubobject <UTankAimComponent>(FName("Aim Component Barak2"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
	{

		TankAimComponent->AimAt(HitLocation);
		
	}

void ATank::SetBarrelReference(UStaticMeshComponent * BarrelToset,FString PutSomeText)
{

	TankAimComponent->SetBarrelReference(BarrelToset);

	UE_LOG(LogTemp,Warning,TEXT("The test from blue print is: %s"),*PutSomeText)
}
