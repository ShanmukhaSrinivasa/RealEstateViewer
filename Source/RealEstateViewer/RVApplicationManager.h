// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RVApplicationManager.generated.h"

class ARVFloorActor;
class ARVTowerActor;

UENUM()
enum class ERVApplicationState : uint8
{
	Startup,
	ProjectOverview,
	Exploring,
	Interior
};

UCLASS()
class REALESTATEVIEWER_API URVApplicationManager : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
	FString CurrentProject;

	UPROPERTY()
	ERVApplicationState CurrentState;

	UFUNCTION(BlueprintCallable)
	void SetApplicationState(ERVApplicationState NewState);

	// Floors
	UFUNCTION(BlueprintCallable)
	void SelectFloor(int32 FloorNumber);

	UFUNCTION(BlueprintCallable)
	void ViewSelectedFloor();

	UFUNCTION(BlueprintCallable)
	FText GetSelectedFloorName() const;

	UFUNCTION(BlueprintCallable)
	FText GetSelectedFloorDescription() const;

	// Towers
	UFUNCTION(BlueprintCallable)
	void SelectTower(int32 TowerNumber);

	UFUNCTION(BlueprintCallable)
	void ViewSelectedTower();

	UFUNCTION(BlueprintCallable)
	FText GetSelectedTowerName() const;

	UFUNCTION(BlueprintCallable)
	FText GetSelectedTowerDescription() const;

private:

	UPROPERTY()
	ARVFloorActor* SelectedFloor = nullptr;

	UPROPERTY()
	ARVTowerActor* SelectedTower = nullptr;
};
