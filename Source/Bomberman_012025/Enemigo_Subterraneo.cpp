// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo_Subterraneo.h"

AEnemigo_Subterraneo::AEnemigo_Subterraneo() {

	auto Asset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Rust.M_Metal_Rust'"));
	if (Asset.Object != nullptr) {

		Mesh->SetMaterial(0, Asset.Object);
	}
}