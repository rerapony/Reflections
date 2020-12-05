// Fill out your copyright notice in the Description page of Project Settings.


#include "Relocatable.h"
#include "cmath"

// Sets default values
ARelocatable::ARelocatable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	circleRadius = 200;
	initNumber = 10;
}

// Called when the game starts or when spawned
void ARelocatable::BeginPlay()
{
	Super::BeginPlay();

	float angleStep = 2 * PI / initNumber;
	const FVector circleCenter = GetActorLocation();

	const float x0 = circleCenter.X;
	const float y0 = circleCenter.Y;

	float spawnAngle = angleStep;

	for (int i = 0; i < initNumber; i++) {

		float x = x0 + circleRadius * cos(spawnAngle);
		float y = y0 + circleRadius * sin(spawnAngle);
		const FVector spawnPoint(x, y, 0);
		const FRotator spawnRotation = (spawnPoint - circleCenter).Rotation();

		AActor* spawnedActor = GetWorld()->SpawnActor<AActor>(actorToSpawn, { x, y, 0 }, spawnRotation);

		spawnAngle += angleStep;
		AfterSpawn(spawnedActor);
	}
}

// Called every frame
void ARelocatable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARelocatable::AfterSpawn(AActor* actor)
{
}

