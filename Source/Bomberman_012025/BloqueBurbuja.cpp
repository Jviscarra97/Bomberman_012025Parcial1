// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueBurbuja.h"


ABloqueBurbuja::ABloqueBurbuja() {
	if (Mesh) {
		static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("Material'/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean'"));
		if (Material.Succeeded()) {
			Mesh->SetMaterial(0, Material.Object);
		}
	}
}
