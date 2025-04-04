// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto.h"
ABloqueConcreto::ABloqueConcreto() {
	auto MaterialAsset = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Concrete_Grime.M_Concrete_Grime'"));
	if (MaterialAsset.Object != nullptr) {
		Mesh->SetMaterial(0, MaterialAsset.Object);
	}

}
