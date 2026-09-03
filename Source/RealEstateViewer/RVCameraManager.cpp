#include "RVCameraManager.h"
#include "Camera/CameraComponent.h"

// Sets default values
ARVCameraManager::ARVCameraManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	RootComponent = Camera;
}

// Called when the game starts or when spawned
void ARVCameraManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARVCameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsMoving)
	{
		return;
	}

	TransitionElapsed += DeltaTime;

	const float Alpha = FMath::Clamp(TransitionElapsed / TransitionDuration, 0.0f, 1.0f);

	const float SmoothAlpha = FMath::InterpEaseInOut(0.0f, 1.0f, Alpha, 2.0f);

	const FVector NewLocation = FMath::Lerp(TransitionStartLocation, TransitionTargetLocation, SmoothAlpha);

	const FRotator NewRotation = FMath::Lerp(TransitionStartRotation, TransitionTargetRotation, SmoothAlpha);

	SetActorLocation(NewLocation);
	SetActorRotation(NewRotation);

	if (Alpha >= 1.0f)
	{
		bIsMoving = false;

		SetActorLocation(TransitionTargetLocation);
		SetActorRotation(TransitionTargetRotation);
	}
}

void ARVCameraManager::ActivateCamera()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (!PlayerController)
	{
		return;
	}

	PlayerController->SetViewTarget(this);
}

void ARVCameraManager::MoveToTarget(USceneComponent* Target)
{
	if (!Target)
	{
		return;
	}

	TransitionStartLocation = GetActorLocation();
	TransitionStartRotation = GetActorRotation();

	TransitionTargetLocation = Target->GetComponentLocation();
	TransitionTargetRotation = Target->GetComponentRotation();

	TransitionElapsed = 0.0f;
	bIsMoving = true;

	UE_LOG(LogTemp, Warning, TEXT("Camera transition started"));
}