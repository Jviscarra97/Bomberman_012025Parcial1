// Fill out your copyright notice in the Description page of Project Settings.


#include "BloquePasto.h"

ABloquePasto::ABloquePasto() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}