// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueOro.h"

ABloqueOro::ABloqueOro() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}