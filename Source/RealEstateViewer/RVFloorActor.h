// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RVFloorActor.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class ARVTowerActor;

UCLASS()
class REALESTATEVIEWER_API ARVFloorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARVFloorActor();

	int32 GetFloorNumber() const;
	FText GetFloorName() const;
	FText GetDescription() const;
	USceneComponent* GetCameraTarget() const;

	ARVTowerActor* GetParentTower() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Floor")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Floor")
	USceneComponent* CameraTarget;

	UPROPERTY(EditAnywhere, Category = "Floor")
	ARVTowerActor* ParentTower = nullptr;

	UPROPERTY(EditAnywhere, Category = "Floor")
	int32 FloorNumber = 1;

	UPROPERTY(EditAnywhere, Category = "Floor")
	FText FloorName;

	UPROPERTY(EditAnywhere, Category = "Floor")
	FText Description;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
