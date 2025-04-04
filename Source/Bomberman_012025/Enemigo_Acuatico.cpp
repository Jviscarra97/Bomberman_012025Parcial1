// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Acuatico.h"
AEnemigo_Acuatico::AEnemigo_Acuatico() {

	auto Asset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean'"));
	if (Asset.Object != nullptr) {

		Mesh->SetMaterial(0, Asset.Object);
	}
}
