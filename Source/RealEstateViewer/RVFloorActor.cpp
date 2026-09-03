#include "RVFloorActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "RVTowerActor.h"

// Sets default values
ARVFloorActor::ARVFloorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = Mesh;

	CameraTarget = CreateDefaultSubobject<USceneComponent>(TEXT("CameraTarget"));

	CameraTarget->SetupAttachment(RootComponent);
}

int32 ARVFloorActor::GetFloorNumber() const
{
	return FloorNumber;
}

FText ARVFloorActor::GetFloorName() const
{
	return FloorName;
}

FText ARVFloorActor::GetDescription() const
{
	return Description;
}

// Called when the game starts or when spawned
void ARVFloorActor::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ARVFloorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

USceneComponent* ARVFloorActor::GetCameraTarget() const
{
	return CameraTarget;
}

ARVTowerActor* ARVFloorActor::GetParentTower() const
{
	return ParentTower;
}