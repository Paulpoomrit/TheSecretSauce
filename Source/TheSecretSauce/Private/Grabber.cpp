// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

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

	const FVector Start = GetComponentLocation();
	const FVector End = Start + GetForwardVector() * this->MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, true);

	float Damage;
	if (HasDamage(Damage))
	{
		PrintDamage(Damage);
	}
}

void UGrabber::PrintDamage(const float& Damage) // Damage -> pass by ref (const)
{
	UE_LOG(LogTemp, Display, TEXT("Damage: %f"), Damage);
}

bool UGrabber::HasDamage(float& OutDamage) // OutDamage -> not const -> is considered outParameter
{
	OutDamage = 10;
	return true;
}

