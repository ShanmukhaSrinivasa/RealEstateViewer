// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RVTowerActor.generated.h"

class USceneComponent;

UCLASS()
class REALESTATEVIEWER_API ARVTowerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARVTowerActor();

	int32 GetTowerNumber() const;
	FText GetTowerName() const;
	FText GetTowerDescription() const;
	USceneComponent* GetCameraTarget() const;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Tower")
	USceneComponent* CameraTarget;

	UPROPERTY(EditAnywhere, Category = "Tower")
	int32 TowerNumber = 1;

	UPROPERTY(EditAnywhere, Category = "Tower")
	FText TowerName;

	UPROPERTY(EditAnywhere, Category = "Tower")
	FText Description;
};
