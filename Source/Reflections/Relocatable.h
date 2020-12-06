// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Relocatable.generated.h"

UCLASS()
class REFLECTIONS_API ARelocatable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARelocatable();

protected:
	float GetRandomAngle() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void AfterSpawn(AActor* Actor);

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere)
	float CircleRadius;

	UPROPERTY(EditAnywhere)
	int32 InitNumber;

	const float MIN_ANGLE = 0;
	const float MAX_ANGLE = 2 * PI;
};
