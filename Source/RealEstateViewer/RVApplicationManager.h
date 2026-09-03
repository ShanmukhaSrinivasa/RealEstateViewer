// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RVApplicationManager.generated.h"

class ARVFloorActor;

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

	UFUNCTION(BlueprintCallable)
	void SelectFloor(int32 FloorNumber);

	UFUNCTION(BlueprintCallable)
	void ViewSelectedFloor();

	UFUNCTION(BlueprintCallable)
	FText GetSelectedFloorName() const;

	UFUNCTION(BlueprintCallable)
	FText GetSelectedFloorDescription() const;

private:

	UPROPERTY()
	ARVFloorActor* SelectedFloor = nullptr;
};
