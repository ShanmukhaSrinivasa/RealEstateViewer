#include "RVGameInstance.h"
#include "RVApplicationManager.h"

void URVGameInstance::Init()
{
	Super::Init();

	ApplicationManager = NewObject<URVApplicationManager>(this);

	ApplicationManager->CurrentProject = TEXT("PrototypeProject");
	ApplicationManager->CurrentState = ERVApplicationState::Startup;

	ApplicationManager->SetApplicationState(ERVApplicationState::ProjectOverview);
	
	UE_LOG(LogTemp, Warning, TEXT("RealEstateViewer GameInstance Initialized"));

	UE_LOG(LogTemp, Warning, TEXT("ApplicationManager Created"));

	UE_LOG(LogTemp, Warning, TEXT("Current Project: %s"), *ApplicationManager->CurrentProject);
}

URVApplicationManager* URVGameInstance::GetApplicationManager() const
{
	return ApplicationManager;
}