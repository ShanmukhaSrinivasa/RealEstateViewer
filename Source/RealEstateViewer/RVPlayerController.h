// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RVPlayerController.generated.h"

class UUserWidget;
class ARVInteractiveActor;

UCLASS()
class REALESTATEVIEWER_API ARVPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ARVPlayerController();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
protected:

	void CheckMouseInteraction();

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> FloorSelectionWidgetClass;

	UPROPERTY()
	UUserWidget* FloorSelectionWidget = nullptr;

	UPROPERTY()
	ARVInteractiveActor* CurrentHoveredActor = nullptr;
};
