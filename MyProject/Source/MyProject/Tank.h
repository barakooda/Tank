// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "TankAimComponent.h" //moving to forward declaration
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste includes only above this line

//forward declaration
class UTankBarrel;
class UTankTurret;
class UTankAimComponent;
//class UTankMovementComponent;
class AProjectile;

UCLASS()
class MYPROJECT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector);
	virtual void BeginPlay() override;
	
	
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void fire();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "SomeText")
	FString SomeText = "Text From Tank.h - yay";




protected:
	
	
	//UPROPERTY(EditDefaultsOnly,BluePrintReadOnly,Category = "TankMovement")
	//UTankMovementComponent* TankMovementComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "TankAim")
	UTankAimComponent* TankAim = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned

	
	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;



	UPROPERTY(EditAnywhere, Category = "Firing")
	float LunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTime = 3; //seconds

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;


	
	float LastFireTime = 0;   //last time tank was firing

	UTankBarrel* Barrel = nullptr;
};
