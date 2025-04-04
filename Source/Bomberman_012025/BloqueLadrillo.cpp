// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLadrillo.h"
ABloqueLadrillo::ABloqueLadrillo() {
	auto AssetMaterial = ConstructorHelpers::FObjectFinder<UMaterial>(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
	if (AssetMaterial.Object) {

		Mesh->SetMaterial(0, AssetMaterial.Object);
	}



}
