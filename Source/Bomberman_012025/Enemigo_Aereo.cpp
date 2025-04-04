// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Aereo.h"

AEnemigo_Aereo::AEnemigo_Aereo() {

	auto Asset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
	if (Asset.Object != nullptr) {

		Mesh->SetMaterial(0, Asset.Object);
	}
}
