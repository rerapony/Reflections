// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"


void AEnemySpawner::AfterSpawn(AActor* actor)
{
    SpawnedEnemies.push_back(dynamic_cast<AEnemy*>(actor));
}

void AEnemySpawner::RespawnActor()
{
    float angleStep = 2 * PI / initNumber;

    float randomNumber = ((float) rand() / (float) initNumber) + 1;
    const FVector circleCenter = GetActorLocation();

    const float x0 = circleCenter.X;
    const float y0 = circleCenter.Y;

    float spawnAngle = angleStep * randomNumber;

    float x = x0 + circleRadius * cos(spawnAngle);
    float y = y0 + circleRadius * sin(spawnAngle);
    const FVector spawnPoint(x, y, 0);
    const FRotator spawnRotation = (circleCenter - spawnPoint).Rotation();

    AActor* spawnedActor = GetWorld()->SpawnActor<AActor>(actorToSpawn, { x, y, 0 }, { 0, spawnRotation.Yaw, 0 });
    AfterSpawn(spawnedActor);
}

void AEnemySpawner::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    const FVector circleCenter = GetActorLocation();

    for (auto it = SpawnedEnemies.begin(); it != SpawnedEnemies.end(); ) {
        AEnemy* a = *it;
        const FVector SpawnedLocation = a->GetActorLocation();
        float distance = FVector::DistXY(circleCenter, SpawnedLocation);

        if (distance >= 3 * circleRadius) {
            auto res = a->Destroy();
            it = SpawnedEnemies.erase(it);

            RespawnActor();
        } else {
            ++it;
        }
    }

}