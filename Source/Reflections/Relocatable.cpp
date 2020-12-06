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

// Called when the game starts or when spawned
void ARelocatable::BeginPlay()
{
	Super::BeginPlay();

	float AngleStep = 2 * PI / InitNumber;
	const FVector CircleCenter = GetActorLocation();

	const float X0 = CircleCenter.X;
	const float Y0 = CircleCenter.Y;

	float SpawnAngle = AngleStep;

	for (int i = 0; i < InitNumber; i++) {

		float X = X0 + CircleRadius * FMath::Cos(SpawnAngle);
		float Y = Y0 + CircleRadius * FMath::Sin(SpawnAngle);
		const FVector SpawnPoint(X, Y, 0);
		const FRotator SpawnRotation = (SpawnPoint - CircleCenter).Rotation();

		AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, { X, Y, 0 }, SpawnRotation);

		SpawnAngle += AngleStep;
		AfterSpawn(SpawnedActor);
	}
}

// Called every frame
void ARelocatable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARelocatable::AfterSpawn(AActor* Actor)
{
}