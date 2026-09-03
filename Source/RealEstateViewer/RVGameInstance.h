// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RVGameInstance.generated.h"

class URVApplicationManager;

/**
 * 
 */
UCLASS()
class REALESTATEVIEWER_API URVGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	URVApplicationManager* GetApplicationManager() const;

private:

	UPROPERTY()
	URVApplicationManager* ApplicationManager;
};
