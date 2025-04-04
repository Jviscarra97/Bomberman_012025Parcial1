// Fill out your copyright notice in the Description page of Project Settings.

#include "BloqueAcero.h"

ABloqueAcero::ABloqueAcero()
{
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Steel.M_Metal_Steel'"));
	if (AssetMaterial.Object != nullptr) {
		Mesh->SetMaterial(0, AssetMaterial.Object);
	}
}

