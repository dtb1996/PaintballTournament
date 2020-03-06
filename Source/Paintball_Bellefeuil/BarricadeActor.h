// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "BarricadeActor.generated.h"

UCLASS()
class PAINTBALL_BELLEFEUIL_API ABarricadeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarricadeActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	virtual void GenerateBoxMesh();
	virtual void CreateBoxMesh(FVector BoxRadius, TArray <FVector> & Vertices, TArray <int32> & Triangles, TArray <FVector> & Normals, TArray <FVector2D> & UVs, TArray <FProcMeshTangent> & Tangents, TArray <FColor> & Colors);
	virtual void PostActorCreated() override;
	virtual void PostLoad() override;

private:
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent * barricadeMesh;
	
};
