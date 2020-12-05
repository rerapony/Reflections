// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Relocatable.generated.h"

UCLASS()
class BLACKSOLUTIONS_API ARelocatable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARelocatable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	virtual void AfterSpawn(AActor* actor);

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> actorToSpawn;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float circleRadius;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int initNumber;
};
