//Dillon Bellefeuille
//GAM-415
//Module 3 Stepping Stone Two
//This class sets up a static mesh and default material for the object and changes the material through an
//overlap method (triggered by the player). The mesh and two materials are defined in the editor
//Based on the "Change Material Mesh" tutorial by Harrison McGuire https://unrealcpp.com/change-material-mesh


#include "DynamicActor.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"


// Sets default values
ADynamicActor::ADynamicActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Creates a mesh component for the object
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetupAttachment(RootComponent);
	RootComponent = MyMesh;

	//Sets up the box component
	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My BoxComponent"));
	MyBoxComponent->InitBoxExtent(FVector(100, 100, 100));
	MyBoxComponent->SetCollisionProfileName("Trigger");
	MyBoxComponent->SetupAttachment(RootComponent);

	//Specifies two materials to be used at runtime
	OnMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OffMaterial"));

	//Calls the overlap function
	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADynamicActor::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ADynamicActor::BeginPlay()
{
	Super::BeginPlay();
	
	//Uncomment to include debug box
	//DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100, 100, 100), FColor::White, true, -1, 0, 10);

	//Sets the object material to intial material
	MyMesh->SetMaterial(0, OffMaterial);
}

// Called every frame
void ADynamicActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Overlap event that dynamically changes the object material during runtime
void ADynamicActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		//Checks to see which material the object is set to
		if (MyMesh->GetMaterial(0) == OffMaterial)
		{
			//Sets object material to second material specified in editor
			MyMesh->SetMaterial(0, OnMaterial);
		}
		else
		{
			//Sets object material to first material specified in editor
			MyMesh->SetMaterial(0, OffMaterial);
		}
	}

}