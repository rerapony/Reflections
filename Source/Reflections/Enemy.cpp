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

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
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

	if (NewLocation.Size() < 1) Destroy();
}

// TakeDamage event
float AEnemy::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= Damage;
	if (Health <= 0) Destroy();

	return 0;
}
