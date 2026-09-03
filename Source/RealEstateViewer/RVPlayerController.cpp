// Fill out your copyright notice in the Description page of Project Settings.


#include "RVPlayerController.h"
#include "RVInteractiveActor.h"
#include "Blueprint/UserWidget.h"
#include "RVCameraManager.h"
#include "Kismet/GameplayStatics.h"

ARVPlayerController::ARVPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARVPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;

	SetInputMode(FInputModeGameAndUI());

	if (FloorSelectionWidgetClass)
	{
		FloorSelectionWidget = CreateWidget<UUserWidget>(this, FloorSelectionWidgetClass);

		if (FloorSelectionWidget)
		{
			FloorSelectionWidget->AddToViewport();

			UE_LOG(LogTemp, Warning, TEXT("Floor Selection Widget Created"));
		}
	}

	ARVCameraManager* CameraManager = Cast<ARVCameraManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ARVCameraManager::StaticClass()));

	if (CameraManager)
	{
		CameraManager->ActivateCamera();

		UE_LOG(LogTemp, Warning, TEXT("RV CameraManager Activated"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("RV CameraManager not found"));
	}

	UE_LOG(LogTemp, Warning, TEXT("RVPlayerController BeginPlay Started"));
}

void ARVPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckMouseInteraction();
}

void ARVPlayerController::CheckMouseInteraction()
{
	
}