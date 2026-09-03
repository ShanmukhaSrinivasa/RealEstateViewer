// Fill out your copyright notice in the Description page of Project Settings.

#include "RVApplicationManager.h"
#include "RVFloorActor.h"
#include "RVTowerActor.h"
#include "Kismet/GameplayStatics.h"
#include "RVCameraManager.h"

void URVApplicationManager::SetApplicationState(ERVApplicationState NewState)
{
	const ERVApplicationState PreviousState = CurrentState;

	CurrentState = NewState;

	const UEnum* StateEnum = StaticEnum<ERVApplicationState>();

	const FString PreviousStateName = StateEnum->GetNameStringByValue(static_cast<int64>(PreviousState));

	const FString NewStateName = StateEnum->GetNameStringByValue(static_cast<int64>(NewState));

	UE_LOG(LogTemp, Warning, TEXT("Application State Changed: %s -> %s"), *PreviousStateName, *NewStateName);
}

void URVApplicationManager::SelectFloor(int32 FloorNumber)
{
	UWorld* World = GetWorld();

	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("SelectFloor failed: World is null"));

		return;
	}

	TArray<AActor*> FloorActors;

	UGameplayStatics::GetAllActorsOfClass(World, ARVFloorActor::StaticClass(), FloorActors);

	for (AActor* Actor : FloorActors)
	{
		ARVFloorActor* FloorActor = Cast<ARVFloorActor>(Actor);

		if (!FloorActor)
		{
			continue;
		}

		if (FloorActor->GetFloorNumber() == FloorNumber)
		{
			SelectedFloor = FloorActor;

			UE_LOG(LogTemp, Warning, TEXT("Floor Selected: %d - %s"), FloorNumber, *FloorActor->GetName());

			return;
		}
	}

	SelectedFloor = nullptr;

	UE_LOG(LogTemp, Warning, TEXT("Floor Not Found: %d"), FloorNumber);
}

void URVApplicationManager::SelectTower(int32 TowerNumber)
{
	UWorld* World = GetWorld();

	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("SelectTower failed: World is null"));
		return;
	}

	TArray<AActor*> TowerActors;

	UGameplayStatics::GetAllActorsOfClass(World, ARVTowerActor::StaticClass(), TowerActors);

	for (AActor* Actor : TowerActors)
	{
		ARVTowerActor* TowerActor = Cast<ARVTowerActor>(Actor);

		if (!TowerActor)
		{
			continue;
		}

		if (TowerActor->GetTowerNumber() == TowerNumber)
		{
			SelectedTower = TowerActor;

			UE_LOG(LogTemp, Warning, TEXT("Tower Selected: %d - %s"), TowerNumber, *TowerActor->GetName());

			return;
		}
	}

	SelectedTower = nullptr;

	UE_LOG(LogTemp, Warning, TEXT("Tower Not Found: %d"), TowerNumber);
}

FText URVApplicationManager::GetSelectedFloorName() const
{
	if (!SelectedFloor)
	{
		return FText::GetEmpty();
	}

	return SelectedFloor->GetFloorName();
}

FText URVApplicationManager::GetSelectedFloorDescription() const
{
	if (!SelectedFloor)
	{
		return FText::GetEmpty();
	}

	return SelectedFloor->GetDescription();
}

FText URVApplicationManager::GetSelectedTowerName() const
{
	if (!SelectedTower)
	{
		return FText::GetEmpty();
	}

	return SelectedTower->GetTowerName();
}

FText URVApplicationManager::GetSelectedTowerDescription() const
{
	if (!SelectedTower)
	{
		return FText::GetEmpty();
	}

	return SelectedTower->GetTowerDescription();
}

void URVApplicationManager::ViewSelectedFloor()
{
	if (!SelectedFloor)
	{
		UE_LOG(LogTemp, Warning, TEXT("ViewSelectedFloor failed: No floor selected"));
		return;
	}

	USceneComponent* CameraTarget = SelectedFloor->GetCameraTarget();

	if (!CameraTarget)
	{
		UE_LOG(LogTemp, Warning, TEXT("ViewSelectedFloor failed: camera target is null"));
		return;
	}

	UWorld* World = GetWorld();

	if (!World)
	{
		return;
	}

	ARVCameraManager* CameraManager = Cast<ARVCameraManager>(UGameplayStatics::GetActorOfClass(World, ARVCameraManager::StaticClass()));

	if (!CameraManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("ViewSelectedFloor failed: Camera Manager not found"));

		return;
	}

	CameraManager->MoveToTarget(CameraTarget);

	UE_LOG(LogTemp, Warning, TEXT("Viewing Floor: %d"), SelectedFloor->GetFloorNumber());

}

void URVApplicationManager::ViewSelectedTower()
{
	if (!SelectedTower)
	{
		UE_LOG(LogTemp, Warning, TEXT("ViewSelectedTower failed: No Tower Selected"));
		return;
	}

	USceneComponent* CameraTarget = SelectedTower->GetCameraTarget();

	if (!CameraTarget)
	{
		UE_LOG(LogTemp, Warning, TEXT("ViewSelectedTower failed: camera target is null"));
		return;
	}

	UWorld* World = GetWorld();

	if (!World)
	{
		return;
	}

	ARVCameraManager* CameraManager = Cast<ARVCameraManager>(UGameplayStatics::GetActorOfClass(World, ARVCameraManager::StaticClass()));

	if (!CameraManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("ViewSelectedTower failed: Camera Manager not found"));

		return;
	}

	CameraManager->MoveToTarget(CameraTarget);

	UE_LOG(LogTemp, Warning, TEXT("Viewing Tower: %d"), SelectedTower->GetTowerNumber());
}