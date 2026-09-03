// Fill out your copyright notice in the Description page of Project Settings.


#include "RVInteractiveActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARVInteractiveActor::ARVInteractiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void ARVInteractiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARVInteractiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

