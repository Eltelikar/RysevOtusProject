// Fill out your copyright notice in the Description page of Project Settings.


#include "InteactableLamp.h"

#include "Components/SphereComponent.h"

#include "Components/MeshComponent.h"

#include "Components/PointLightComponent.h"

#include "UObject/ConstructorHelpers.h"

#include "Components/StaticMeshComponent.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
AInteactableLamp::AInteactableLamp()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("OverlapSphere"));
	OverlapSphere->SetupAttachment(RootComponent);
	OverlapSphere->SetSphereRadius(50.f);
	OverlapSphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	LampMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LampMesh"));
	LampMesh->SetupAttachment(OverlapSphere);
	LampMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
	LampMeshAsset(TEXT("/Game/Weapon_Pack/Mesh/Props/Interior/SM_Wall_Torch1.SM_Wall_Torch1"));
	LampMesh->SetStaticMesh(LampMeshAsset.Object);
	

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Light->SetupAttachment(LampMesh);
	Light->SetRelativeLocation(FVector(50.0f, 5.0f, 0.0f));
	Light->SetLightColor(FLinearColor(0.4f, 0.09f, 0.0f, 1.0f));

	FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));
	FireParticles->SetupAttachment(LampMesh);
	static ConstructorHelpers::FObjectFinder<UParticleSystem>
	FireParticlesAsset(TEXT("/Script/Engine.ParticleSystem'/Game/Weapon_Pack/Effects/Particles/Fire/P_TorchFire.P_TorchFire'"));
	FireParticles->SetTemplate(FireParticlesAsset.Object);
	FireParticles->SetRelativeLocation(FVector(50.0f, 5.0f, 0.0f));
}

// Called when the game starts or when spawned
void AInteactableLamp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteactableLamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
