// Fill out your copyright notice in the Description page of Project Settings.

#include "Relocatable.h"
#include "Math/UnrealMathVectorConstants.h" 

// Sets default values
ARelocatable::ARelocatable()
	: CircleRadius(200)
	, InitNumber(10)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float ARelocatable::GetRandomAngle() const {
	float random = ((float)rand()) / MAX_ANGLE;
	float range = MAX_ANGLE;

	return (random * range) + MIN_ANGLE;
}

// Called every frame
void ARelocatable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARelocatable::AfterSpawn(AActor* Actor)
{
}