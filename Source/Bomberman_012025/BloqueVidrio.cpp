// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueVidrio.h"

ABloqueVidrio::ABloqueVidrio() {

	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Glass.M_Glass'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);



		}



	}


}