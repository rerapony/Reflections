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
class REFLECTIONS_API AEnemySpawner : public ARelocatable
{
	GENERATED_BODY()


public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;


private:

	virtual void AfterSpawn(AActor* actor) override;
	void RespawnActor();

	std::vector<AEnemy*> SpawnedEnemies;
	
};
