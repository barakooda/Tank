// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankTrack.h"



void UTankTrack::TrackThrottle(float Throttle)
{
	//UE_LOG(LogTemp, Warning, TEXT("The throttle of %s is : %f"), *(GetName()), Throttle)

		//TODO Clamp Throttle so designer will not able to mess our project 


	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent> ( GetOwner()->GetRootComponent() );

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}