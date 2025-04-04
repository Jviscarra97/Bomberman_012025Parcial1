// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABloque : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloque();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
	UStaticMeshComponent* Mesh;

private:
	
	FVector PosInicial;
	FVector PosFinal;
	float TiempoDeMovimiento;
	float TiempoTranscurrido;

public:

	void IniciarMovimiento(FVector NuevaPosObjetivo, float Tiempo);
	void MoverBloque(float DeltaTime);

};
