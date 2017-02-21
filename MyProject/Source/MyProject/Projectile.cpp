// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "PMC.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject <UPMC>( FName("Projectile Movement Component") );
	ProjectileMovement->bAutoActivate = false;

	
	
	CollisionMesh = CreateDefaultSubobject <UStaticMeshComponent>(FName("Collision_Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LunchBlast = CreateDefaultSubobject <UParticleSystemComponent>(FName("Lunch_Blast"));
	LunchBlast -> AttachTo(RootComponent);
	
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AProjectile::LunchProjectile(float LunchSpeed) 
{
	//UE_LOG(LogTemp, Warning, TEXT("lunch Speed is: %f"), LunchSpeed);

	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector*LunchSpeed);
	ProjectileMovement->Activate();
}

