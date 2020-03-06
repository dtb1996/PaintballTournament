// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

//Dillon Bellefeuille
//GAM-415
//The added code enables a decal to be dynamically spawned on an actor in the projectile's OnHit method
//Based on the "Paintballs" tutorial by Dean Ashford https://www.youtube.com/watch?v=J11jkWZtKp4
//This satisfies requirement GAM-415-02: Apply texture and material to meshes adding 2D images to 3D models and
//GAM-415-03: Apply shaders to geometric objects in game development environments by employing graphics application program interfaces

#include "Paintball_BellefeuilProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Paintball_BellefeuilCharacter.h"
#include "Components/SphereComponent.h"

APaintball_BellefeuilProjectile::APaintball_BellefeuilProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &APaintball_BellefeuilProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

}

void APaintball_BellefeuilProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

	}

	//----------------------------------------------------------------------------------------------------------------
	//Dynamic decal code from Stepping-Stone Four
	//----------------------------------------------------------------------------------------------------------------

	//Creates a dynamic instanced material from the specified decal
	DynamicDecal = UMaterialInstanceDynamic::Create(DecalToAdd, this);

	//Sets the number of frames parameter
	DynamicDecal->SetScalarParameterValue("Frame", float(FMath::RandRange(0, NumberOfFrames - 1)));

	//Sets the color parameter
	DynamicDecal->SetVectorParameterValue("Color", FLinearColor::MakeRandomColor());

	//Spawns the decal at the location of impact
	UGameplayStatics::SpawnDecalAtLocation(OtherActor, DynamicDecal, FVector(UKismetMathLibrary::RandomFloatInRange(25.f, 60.f)), Hit.Location, UKismetMathLibrary::MakeRotFromX(Hit.ImpactNormal), lifespan);

	//Play the sound if specified
	if (SplatSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, SplatSound, GetActorLocation());
	}

	//Destroys the projectile
	Destroy();
	
}