// Fill out your copyright notice in the Description page of Project Settings.


#include "RVGameMode.h"
#include "RVPlayerController.h"

ARVGameMode::ARVGameMode()
{
	PlayerControllerClass = ARVPlayerController::StaticClass();
}
