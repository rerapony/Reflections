// Fill out your copyright notice in the Description page of Project Settings.


#include "EmitterSpawner.h"
#include "TimerManager.h"
#include "Engine/World.h"


// Sets default values
AEmitterSpawner::AEmitterSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEmitterSpawner::BeginPlay()
{
	Super::BeginPlay();

	const FVector CircleCenter = GetActorLocation();
	const float X0 = CircleCenter.X;
	const float Y0 = CircleCenter.Y;

	float SpawnAngle = GetRandomAngle();

	float X = X0 + CircleRadius * FMath::Cos(SpawnAngle);
	float Y = Y0 + CircleRadius * FMath::Sin(SpawnAngle);


	const FVector SpawnPoint(X, Y, 0);
	FRotator SpawnRotation = (CircleCenter - SpawnPoint).Rotation();

	if (SpawnedActor == nullptr) {
		SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, { X, Y, 0 }, { 0, SpawnRotation.Yaw, 0 });
	}

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEmitterSpawner::MoveEmitter, TimeInterval, true);

}

void AEmitterSpawner::MoveEmitter() {

	const FVector CircleCenter = GetActorLocation();
	const float X0 = CircleCenter.X;
	const float Y0 = CircleCenter.Y;

	float SpawnAngle = GetRandomAngle();

	float X = X0 + CircleRadius * FMath::Cos(SpawnAngle);
	float Y = Y0 + CircleRadius * FMath::Sin(SpawnAngle);

	const FVector NewLocation(X, Y, 0);
	FRotator NewRotation = (CircleCenter - NewLocation).Rotation();

	if (SpawnedActor != nullptr) {
		SpawnedActor->SetActorLocation(NewLocation);
		SpawnedActor->SetActorRotation({ 0, NewRotation.Yaw, 0 });
	}
	else {
		SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, NewLocation, { 0, NewRotation.Yaw, 0 });
	}
}