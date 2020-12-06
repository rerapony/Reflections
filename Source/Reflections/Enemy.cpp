// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
	: MovementSpeed(200)
	, MaxHealth(100)
	, Health(MaxHealth)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector OldLocation = GetActorLocation();
	FVector NewLocation = OldLocation + GetActorForwardVector() * MovementSpeed * DeltaTime;
	SetActorLocation(NewLocation);
	NewLocation.Z = OldLocation.Z;
}
