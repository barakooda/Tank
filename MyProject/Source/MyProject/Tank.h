// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "TankAimComponent.h" //moving to forward declaration
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste includes only above this line

//forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class MYPROJECT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;
	




protected:
	
	

	//UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "TankAim")
	//UTankAimComponent* TankAim = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned

	
	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;



	//UPROPERTY(EditAnywhere, Category = "Firing")
	//float LunchSpeed = 4000;

	
};
