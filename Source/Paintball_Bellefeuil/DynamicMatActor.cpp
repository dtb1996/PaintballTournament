//Dillon Bellefeuille
//GAM-415
//This class sets the foundation for a blueprint cube actor with parameters that change the material in the BeginPlay function
//Based on the "Dynamic Materials" tutorial by Orfeas Eleftheriou https://orfeasel.com/dynamic-materials/
//This satisfies GAM-415-02: Apply texture and material to meshes adding 2D images to 3D models and
//Applies physical characteristics to 3D objects through parameters

#include "DynamicMatActor.h"


// Sets default values
ADynamicMatActor::ADynamicMatActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initializes the static mesh component
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));

}

// Called when the game starts or when spawned
void ADynamicMatActor::BeginPlay()
{
	Super::BeginPlay();

	//Get the first material of the static mesh and turn it into a material instance
	UMaterialInstanceDynamic* DynamicMatInstance = StaticMesh->CreateAndSetMaterialInstanceDynamic(0);

	//Generate random RGB and Alpha values for our Vector Parameter
	FLinearColor RandomColor;
	RandomColor.R = FMath::RandRange(0, 1);
	RandomColor.G = FMath::RandRange(0, 1);
	RandomColor.B = FMath::RandRange(0, 1);
	RandomColor.A = FMath::RandRange(0, 1);

	//If we have a valid dynamic material instance, modify its parameters
	if (DynamicMatInstance)
	{
		DynamicMatInstance->SetVectorParameterValue(FName("ColorParam"), RandomColor);
		DynamicMatInstance->SetScalarParameterValue(FName("MetalParam"), FMath::RandRange(0, 1));
	}
	
}

// Called every frame
void ADynamicMatActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

