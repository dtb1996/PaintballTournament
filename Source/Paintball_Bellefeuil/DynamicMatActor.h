// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicMatActor.generated.h"

UCLASS()
class PAINTBALL_BELLEFEUIL_API ADynamicMatActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADynamicMatActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Declares a static mesh component visible in the editor
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;
	
};
