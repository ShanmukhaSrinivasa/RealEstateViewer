#include "RVTowerActor.h"
#include "Components/SceneComponent.h"

// Sets default values
ARVTowerActor::ARVTowerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CameraTarget = CreateDefaultSubobject<USceneComponent>(TEXT("CameraTarget"));

	RootComponent = CameraTarget;
}

int32 ARVTowerActor::GetTowerNumber() const
{
	return TowerNumber;
}

FText ARVTowerActor::GetTowerName() const
{
	return TowerName;
}

FText ARVTowerActor::GetTowerDescription() const
{
	return Description;
}

USceneComponent* ARVTowerActor::GetCameraTarget() const
{
	return CameraTarget;
}