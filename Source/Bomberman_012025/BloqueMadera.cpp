// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"
ABloqueMadera::ABloqueMadera()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}


}
