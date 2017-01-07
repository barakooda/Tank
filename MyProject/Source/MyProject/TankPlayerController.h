// Barakooda

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


//forword declartion
class UTankAimComponent;


//class UTankAimComponent;
UCLASS()
class MYPROJECT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
	//start aim on marker

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MarkXLocation")
		float MarkXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "MarkYLocation")
		float MarkYLocation = 0.33333;

protected:

	
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimComponent* AimComponentRef);
	
	
private:

	UTankAimComponent* TankAim = nullptr;

	bool GetLookDirection(FVector2D, FVector&) const;
	void AimOnMarker();
	bool GetSightRayHitLocation(FVector &) const;
	bool GetLookVectorHitLocation(FVector &,FVector &) const ;
	
	
	float LineTraceRange = 1000000;

};
 