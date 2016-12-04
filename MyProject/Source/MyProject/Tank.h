// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "TankAimComponent.h" //moving to forward declaration
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //paste includes only above this line

//forward declaration
class UTankBarrel;
class UTankTurret;
class UTankAimComponent;


UCLASS()
class MYPROJECT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector);
	
	UFUNCTION(BluePrintCallable, Category= Setup)
	void SetBarrelReference(UTankBarrel* BarrelToset,FString PutSomeText);

	UFUNCTION(BluePrintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet, FString PutSomeText);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = SomeText)
	FString SomeText = "Text From Tank.h - yay";




protected:
	UTankAimComponent* TankAimComponent = nullptr;
	UTankAimComponent* TankAimComponent2 = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	//virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LunchSpeed = 100000;
};
