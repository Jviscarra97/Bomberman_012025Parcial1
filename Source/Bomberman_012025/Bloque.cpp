// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque.h"

// Sets default values
ABloque::ABloque()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent"); //creamos un componente para el actor
	RootComponent = Mesh;

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}


}

// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverBloque(DeltaTime);
}
void ABloque::IniciarMovimiento(FVector NuevaPosObjetivo, float Tiempo)
{
	PosInicial = GetActorLocation(); // Guardamos la posici�n inicial
	PosFinal = NuevaPosObjetivo; // Establecemos la nueva posici�n objetivo
	TiempoDeMovimiento = Tiempo; // Establecemos el tiempo de movimiento
	TiempoTranscurrido = 0.0f; // Reiniciamos el tiempo transcurrido
}
void ABloque::MoverBloque(float DeltaTime)
{
	if (TiempoTranscurrido < TiempoDeMovimiento)
	{
		// Calculamos el porcentaje de tiempo transcurrido
		TiempoTranscurrido += DeltaTime;
		float progreso = FMath::Clamp(TiempoTranscurrido / TiempoDeMovimiento, 0.0f, 1.0f);
		
		// Interpolamos la posici�n usando Lerp
		FVector NuevaPos = FMath::Lerp(PosInicial, PosFinal, progreso);
		SetActorLocation(NuevaPos); // Actualizamos la posici�n del bloque
		
	}
}

