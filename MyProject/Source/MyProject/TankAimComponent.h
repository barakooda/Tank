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
	Locked,
	OutOfRounds
};

//forward decleration 
class UTankBarrel;
class UTankTurret;
class AProjectile;



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

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void fire();
	
	//void SetBarrelReference(UTankBarrel* BarrelToSet);
	//void SetTurretReference(UTankTurret* TurretToSet);

	// Called when the game starts
	virtual void BeginPlay() override;
	
	
	//virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	EFiringStatus GetFireingState() const;

	void AimAt(FVector,float);
	
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	int32 GetLeftRounds() const;


protected:
	UPROPERTY(BluePrintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reload;

	
	
	
	
	
private:

	// Called every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	
	bool IsBarrelMoving()	;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTime = 3; //seconds

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 Rounds = 3;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	UTankAimComponent();
	
	//the component
	UTankAimComponent* TankAim = nullptr;

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	FVector AimDirection = FVector(0,0,0);
	void BarrelToAim(FVector);
	void TurretToAim(FVector);

	void RoundsCountDown();



	float LastFireTime = 0;   //last time tank was firing

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LunchSpeed = 4000;

	
	
};
