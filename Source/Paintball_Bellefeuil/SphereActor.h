// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "SphereActor.generated.h"

UCLASS()
class PAINTBALL_BELLEFEUIL_API ASphereActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASphereActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UParticleSystemComponent *OurParticleSystem;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SphereMesh;

	bool SetActorLocation(const FVector & NewLocation, bool bSweep, FHitResult * OutSweepHitResult, ETeleportType Teleport);
};
