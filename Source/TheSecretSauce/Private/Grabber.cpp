// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator GrabberRotation = GetComponentRotation();
	FString GrabberRotationStr = GrabberRotation.ToCompactString();
	UE_LOG(LogTemp, Warning, TEXT("The Grabber's Rotation: %s"), *GrabberRotationStr)

	UWorld* World = GetWorld();
	float TimeElapsed = World->TimeSeconds;
	UE_LOG(LogTemp, Warning, TEXT("Time Elapsed: %f"), TimeElapsed);
	
}

