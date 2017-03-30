// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "PMC.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovement = CreateDefaultSubobject <UPMC>( FName("Projectile Movement Component") );
	ProjectileMovement->bAutoActivate = false;

	
	
	CollisionMesh = CreateDefaultSubobject <UStaticMeshComponent>(FName("Collision_Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LunchBlast = CreateDefaultSubobject <UParticleSystemComponent>(FName("Lunch_Blast"));
	LunchBlast -> AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);

	HitBlast = CreateDefaultSubobject <UParticleSystemComponent>(FName("Hit_Blast"));
	HitBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	HitBlast->bAutoActivate = false;

	ExplosionForce = CreateDefaultSubobject <URadialForceComponent>(FName("Explosion_Force"));
	ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//ExplosionForce->bAutoActivate = false;
	
} 

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
	bool check = false;

	UE_LOG(LogTemp, Warning, TEXT("%i"),check);
	
}

/*
// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
*/

void AProjectile::LunchProjectile(float LunchSpeed) 
{
	//UE_LOG(LogTemp, Warning, TEXT("lunch Speed is: %f"), LunchSpeed);

	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector*LunchSpeed);
	ProjectileMovement->Activate();
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("I`m here %f"), GetWorld()->GetRealTimeSeconds() );
	LunchBlast->Deactivate();
	HitBlast->Activate();
	ExplosionForce->FireImpulse();
	SetRootComponent(HitBlast);
	CollisionMesh->DestroyComponent();

	UGameplayStatics::ApplyRadialDamage(
		this,
		ProjectileDamage,
		GetActorLocation(),
		ExplosionForce->Radius,
		UDamageType::StaticClass(),
		TArray<AActor*>() // damage all actors

		);

	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, & AProjectile::OnTimerExpire, DestroyDelay, false);

}

void AProjectile::OnTimerExpire()
{
	Destroy();
}
