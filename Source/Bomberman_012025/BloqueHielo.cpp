// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueHielo.h"
ABloqueHielo::ABloqueHielo()
{
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Rock_Slate.M_Rock_Slate'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}


}
