// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 Tank Track (better for dunes)
 */
UCLASS( meta = (BluePrintSpawnableComponent),hidecategories = ("Lighting","Materials","Rendering") )
class MYPROJECT_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Set Throttle to track
	UFUNCTION(BluePrintCallable, Category = "Input")
	void TrackThrottle(float Throttle);
	
	//max Drive Force Newton 
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxForce = 18000000.0; //45 ton tank and 2.7 accelration m/s

private:
	UTankTrack();

	virtual void BeginPlay() override;
	
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void ApplySideWaysForce();

	void DriveTrack();

	float CurrentThrottle = 0;

};
