// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RVCameraManager.generated.h"

class UCameraComponent;
class USceneComponent;

UCLASS()
class REALESTATEVIEWER_API ARVCameraManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARVCameraManager();

	UFUNCTION(BlueprintCallable)
	void ActivateCamera();

	UFUNCTION(BlueprintCallable)
	void MoveToTarget(USceneComponent* Target);

protected:

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnyWhere, Category = "Camera")
	float TransitionDuration = 1.5f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	bool bIsMoving = false;
	float TransitionElapsed = 0.0f;
	FVector TransitionStartLocation;
	FRotator TransitionStartRotation;
	FVector TransitionTargetLocation;
	FRotator TransitionTargetRotation;
};
