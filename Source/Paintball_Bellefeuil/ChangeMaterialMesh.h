#pragma once

#include "GameFramework/Actor.h"
#include "ChangeMaterialMesh.generated.h"

class UBoxComponent;

UCLASS()
class  PAINTBALL_BELLEFEUIL_API AChangeMaterialMesh : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChangeMaterialMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
		class UMaterialInterface* OnMaterial;

	UPROPERTY(EditAnywhere)
		class UMaterialInterface* OffMaterial;

	UPROPERTY()
		class UBoxComponent* MyBoxComponent;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};