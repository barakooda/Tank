// Barakooda

#include "MyProject.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!ensure(LeftTrackToSet && RightTrackToSet)) { return; } //ensure
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	
	if ( !ensure(LeftTrack && RightTrack) ) { return; } //ensure
	LeftTrack->TrackThrottle(Throw);
	RightTrack->TrackThrottle(Throw);


}

void UTankMovementComponent::IntendRotateRight(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("The throttle of %s is : %f"), *(GetName()), Throw);
	LeftTrack->TrackThrottle(Throw);
	RightTrack->TrackThrottle(-Throw);

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) 
{
	
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AiForwardIntend = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, AiForwardIntend);
	FVector up = FVector::CrossProduct(TankForward, AiForwardIntend);
	//float RotateThrow = FVector::Size(up);

	IntendRotateRight(up.Z);
	IntendMoveForward(ForwardThrow);

	//UE_LOG(LogTemp,Warning,TEXT("Tank Name : %s , Velocity : %s"),*GetOwner()->GetName(), *up.ToString())
}





