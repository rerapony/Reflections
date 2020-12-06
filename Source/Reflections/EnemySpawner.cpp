// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"



void AEnemySpawner::AfterSpawn(AActor* actor)
{
    SpawnedEnemies.push_back(dynamic_cast<AEnemy*>(actor));
}

void AEnemySpawner::RespawnActor()
{
    const FVector CircleCenter = GetActorLocation();
    const float X0 = CircleCenter.X;
    const float Y0 = CircleCenter.Y;

    float SpawnAngle = GetRandomAngle();

    float X = X0 + CircleRadius * FMath::Cos(SpawnAngle);
    float Y = Y0 + CircleRadius * FMath::Sin(SpawnAngle);

    const FVector SpawnPoint(X, Y, 0);
    const FRotator SpawnRotation = (CircleCenter - SpawnPoint).Rotation();

    AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, { X, Y, 0 }, { 0, SpawnRotation.Yaw, 0 });
    AfterSpawn(SpawnedActor);
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
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
        FRotator SpawnRotation = (CircleCenter - SpawnPoint).Rotation();

        AActor* spawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, { X, Y, 0 }, { 0, SpawnRotation.Yaw, 0 });

        SpawnAngle += AngleStep;
        AfterSpawn(spawnedActor);
    }
}

void AEnemySpawner::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    const FVector circleCenter = GetActorLocation();

    for (auto it = SpawnedEnemies.begin(); it != SpawnedEnemies.end(); ) {
        AEnemy* a = *it;
        const FVector SpawnedLocation = a->GetActorLocation();
        float distance = FVector::DistXY(circleCenter, SpawnedLocation);

        if (distance >= 3 * CircleRadius || SpawnedLocation.Size() < 1 || a->IsDestroyed) {
            auto res = a->Destroy();
            it = SpawnedEnemies.erase(it);

            RespawnActor();
        }
        else {
            ++it;
        }
    }

}