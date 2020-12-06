// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Relocatable.h"
#include "GameFramework/Actor.h"
#include "EmitterSpawner.generated.h"

UCLASS()
class REFLECTIONS_API AEmitterSpawner : public ARelocatable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEmitterSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void MoveEmitter();

	UPROPERTY(EditAnywhere)
	float TimeInterval;

private:
	FTimerHandle TimerHandle;
	AActor* SpawnedActor;
};


