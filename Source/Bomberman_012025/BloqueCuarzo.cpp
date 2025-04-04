// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueCuarzo.h"
ABloqueCuarzo::ABloqueCuarzo() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Copper.M_Metal_Copper'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}
