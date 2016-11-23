// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
	ATank* GetControlledTank() const;
	
	//start aim on marker

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MarkXLocation)
		float MarkXLocation = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MarkYLocation)
		float MarkYLocation = 0.33333;
	
private:
	
	bool GetLookDirection(FVector2D, FVector&) const;
	void AimOnMarker();
	bool GetSightRayHitLocation(FVector &) const;
	bool GetLookVectorHitLocation(FVector &,FVector &) const ;
	
	ATank* CurrentPossesedTank = nullptr ;
	float LineTraceRange = 1000000;

};
 