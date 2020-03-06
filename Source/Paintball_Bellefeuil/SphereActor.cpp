// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereActor.h"


// Sets default values
ASphereActor::ASphereActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Adds a sphere root component
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	//Creates and positions a mesh component
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("StaticMesh'/Game/Geometry/Meshes/Sphere.Sphere'"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	//SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere Mesh"));
	//SphereMesh->SetMobility(EComponentMobility::Movable);


}

// Called when the game starts or when spawned
void ASphereActor::BeginPlay()
{
	Super::BeginPlay();

	//Get current location
	FVector ActorLocation = GetActorLocation();

	//Moves the actor
	ActorLocation.Z += 1000.f;

	//Set the location
	FHitResult HitResult;
	SetActorLocation(ActorLocation, false, &HitResult, ETeleportType::None);
	
}

// Called every frame
void ASphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ASphereActor::SetActorLocation(const FVector & NewLocation, bool bSweep, FHitResult * OutSweepHitResult, ETeleportType Teleport)
{
	
	
	return true;
}