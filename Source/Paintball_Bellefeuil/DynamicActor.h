// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "DynamicActor.generated.h"

UCLASS()
class PAINTBALL_BELLEFEUIL_API ADynamicActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADynamicActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Allows the mesh to be specified in the editor
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MyMesh;

	//Allows the material to be specified in the editor
	UPROPERTY(EditAnywhere)
	class UMaterial* OnMaterial;

	//Allows the material to be specified in the editor
	UPROPERTY(EditAnywhere)
	class UMaterial* OffMaterial;

	//Declares a box component to be used for overlap
	UPROPERTY()
	class UBoxComponent* MyBoxComponent;

	//Declares the overlap function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
};
