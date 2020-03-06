// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine.h"
#include "Components/DecalComponent.h"
#include "GameFramework/PlayerController.h"
#include "Paintball_BellefeuilProjectile.generated.h"

UCLASS(config=Game)
class APaintball_BellefeuilProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	class USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;

public:
	APaintball_BellefeuilProjectile();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

	//------------------------------------------------------------------------------------------------------------------------------
	//Decal variables
	//------------------------------------------------------------------------------------------------------------------------------

	//Allows the decal material to be specific in the editor
	UPROPERTY(EditAnywhere)
		UMaterialInterface* DecalToAdd;

	//Lifespan determines how long the paint splat lasts(0 = forever)
	UPROPERTY(EditAnywhere)
		float lifespan = 5;

	//Variable for the number of frames
	UPROPERTY(EditAnywhere)
		int NumberOfFrames = 4;

	//Sets up a MaterialInstanceDynamic to hold the decal
	UPROPERTY(EditAnywhere)
		UMaterialInstanceDynamic* DynamicDecal;

	// Sound to play each time the paintball hits 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* SplatSound;

};

