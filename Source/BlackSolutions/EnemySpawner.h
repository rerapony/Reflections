// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Relocatable.h"
#include "Enemy.h"
#include "EnemySpawner.generated.h"

/**
 * 
 */
UCLASS()
class BLACKSOLUTIONS_API AEnemySpawner : public ARelocatable
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;


private:
		
	virtual void AfterSpawn(AActor* actor) override;
	void RespawnActor();

	std::vector<AEnemy*> SpawnedEnemies;
};
