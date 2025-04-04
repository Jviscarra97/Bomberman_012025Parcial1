// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Terrestre.h"

AEnemigo_Terrestre::AEnemigo_Terrestre() {

	auto Asset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));
	if (Asset.Object != nullptr) {

		Mesh->SetMaterial(0, Asset.Object);
	}
}
