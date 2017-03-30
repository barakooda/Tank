// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "TankAimComponent.h" //moving to forward declaration
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste includes only above this line

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

//forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class MYPROJECT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,Category = "Health")
	float GetHealthPercentage() const;
	
	virtual void BeginPlay() override;

//called by the engine when actor damage is dealt

	FTankDelegate OnDeath;

	virtual float TakeDamage(
	float DamageAmount,
	struct FDamageEvent const & DamageEvent,
	class AController * EventInstigator,
	AActor * DamageCauser
	) override;

	


protected:
	
	

	//UPROPERTY(EditDefaultsOnly, BluePrintReadOnly, Category = "TankAim")
	//UTankAimComponent* TankAim = nullptr;

private:

	UPROPERTY (EditDefaultsOnly,Category = "Setup")
	int32 StartingHealth = 200;
	
	UPROPERTY(VisibleAnywhere,Category = "Health")
	int32 CurrentHealth ; //inttilaize in begin play 


	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned

	
	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;



	//UPROPERTY(EditAnywhere, Category = "Firing")
	//float LunchSpeed = 4000;

	
};
