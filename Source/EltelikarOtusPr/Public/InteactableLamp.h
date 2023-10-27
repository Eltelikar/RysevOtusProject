// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteactableLamp.generated.h"

UCLASS()
class ELTELIKAROTUSPR_API AInteactableLamp : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	AInteactableLamp();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USphereComponent* OverlapSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* LampMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPointLightComponent* Light;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UParticleSystemComponent* FireParticles;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	

 };
