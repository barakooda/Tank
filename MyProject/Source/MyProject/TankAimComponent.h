// Barakooda

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"


//Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Reload,
	Aim,
	Locked
};

//forward decleration 
class UTankBarrel;
class UTankTurret;



//hold aim properties

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	
	void AimLocation(FVector HitLocation);

	UFUNCTION (BlueprintCallable,Category="TankAim")
	void InitialiseAim(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	
	//void SetBarrelReference(UTankBarrel* BarrelToSet);
	//void SetTurretReference(UTankTurret* TurretToSet);

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	void AimAt(FVector,float);

	

protected:
	UPROPERTY(BluePrintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reload;

	
	
	
	
	
private:
	UTankAimComponent();

	UTankAimComponent* TankAim = nullptr;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void BarrelToAim(FVector);
	void TurretToAim(FVector);

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LunchSpeed = 4000;
	
};
