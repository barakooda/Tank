// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	
}

void UTankTrack::BeginPlay() 
{
	
	UE_LOG(LogTemp,Warning,TEXT("Begin track work"))
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
	
}


void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("I`m here %f"), GetWorld()->GetRealTimeSeconds() );
	ApplySideWaysForce();
	CurrentThrottle = 0;
}




void UTankTrack::ApplySideWaysForce()
{
	
	FVector TrackVel = GetComponentVelocity();
	FVector TrackHeading = GetForwardVector();

	float Slippage = FVector::DotProduct(GetRightVector(), TrackVel);
	FVector SlippageSpeed = Slippage * GetRightVector();

	//calculate accleration 
	
	auto CorrectAcceleration = -SlippageSpeed / GetWorld()->GetDeltaSeconds();

	//f = ma
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectForce = CorrectAcceleration * TankRoot->GetMass() * 0.5;

	TankRoot->AddForce(CorrectForce);

}

void UTankTrack::DriveTrack()
{

	FVector ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxForce;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

}

void UTankTrack::TrackThrottle(float Throttle)
{

	CurrentThrottle = FMath::Clamp<float>( (CurrentThrottle + Throttle),-1.0,1.0 );
	DriveTrack();
	CurrentThrottle = 0;

}