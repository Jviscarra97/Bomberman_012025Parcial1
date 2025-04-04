// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeLevel1.h"
#include "Enemigo.h"
#include "Enemigo_Aereo.h"
#include "Enemigo_Subterraneo.h"
#include "Enemigo_Terrestre.h"
#include "Enemigo_Acuatico.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueLadrillo.h"
#include "BloqueConcreto.h"
#include "BloqueMadera.h"
#include "BloqueCuarzo.h"
#include "BloqueBurbuja.h"
#include "BloqueVidrio.h"
#include "BloqueHielo.h"
#include "BloqueOro.h"
#include "BloquePasto.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
AGameModeLevel1::AGameModeLevel1() {
	
    PrimaryActorTick.bCanEverTick = true;
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != nullptr)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}
void AGameModeLevel1::BeginPlay()
{
    Super::BeginPlay();
    FVector SpawnLocation = FVector(0.0f, 0.0f, 600.0f);
    float Espaciado = 600.0f;
    FVector Bloque_Inicial = FVector(-14953.0, -14984.187776, 0.0f);
    TArray<FVector> Posiciones0; // para guardar los creos
    if (GetWorld())
    {
        for (int fila = 0; fila < MapaBloques.Num(); fila++)//Bucle para generar 
        {
            for (int columna = 0; columna < MapaBloques[fila].Num(); columna++)
            {
                int32 valor = MapaBloques[fila][columna];
                FVector Ubicacion_de_Bloques = Bloque_Inicial + FVector(fila * Espaciado, columna * Espaciado, 0);
                Spawnearbloques(Ubicacion_de_Bloques, valor);
                if (valor == 0) {
                    Posiciones0.Add(Ubicacion_de_Bloques);
                }
            }
        }
        MoverBloque();
        SpawnEnemigoSubterraneo();
        SpawnEnemigoTerrestre();
        SpawnEnemigoAcuatico();
        SpawnEnemigoAereo();
    }
    UE_LOG(LogTemp, Warning, TEXT("Bloques generados: %d"), TodosLosBloques.Num());
}

void AGameModeLevel1::Spawnearbloques(FVector Ubicacion, int32 Bloque) {
    ABloque* TipoBloque = nullptr;
    switch (Bloque)
    {

    case 1:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 2:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 3:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 4:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 5:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueCuarzo>(ABloqueCuarzo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 6:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 7:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueBurbuja>(ABloqueBurbuja::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 8:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueHielo>(ABloqueHielo::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 9:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloqueVidrio>(ABloqueVidrio::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    case 10:
    {
        TipoBloque = GetWorld()->SpawnActor<ABloquePasto>(ABloquePasto::StaticClass(), Ubicacion, FRotator::ZeroRotator);
        break;
    }
    default:
        break;
    }
    if (TipoBloque) {
        TipoBloque->SetActorScale3D(FVector(6.0f, 6.0f, 5.0f));
        TodosLosBloques.Add(TipoBloque);

    }
    if (!BloquesPorTipo.Contains(Bloque)) {
        BloquesPorTipo.Add(Bloque, TArray<AActor*>());
    }
    BloquesPorTipo[Bloque].Add(TipoBloque);


}
void AGameModeLevel1::SpawnearBloques(FVector Posicion, int32 valor)
{
}
void AGameModeLevel1::MoverBloque() {
    for (auto& Par : BloquesPorTipo) {
        TArray<AActor*>& Bloques = Par.Value;

        if (Bloques.Num() > 0)
        {
            int32 CantidadAMover = FMath::Min(20, Bloques.Num());

            for (int32 i = 0; i < CantidadAMover; i++)
            {
                int32 IndiceAleatorio = FMath::RandRange(0, Bloques.Num() - 1);
                AActor* BloqueSeleccionado = Bloques[IndiceAleatorio];

                ABloque* BloqueBase = Cast<ABloque>(BloqueSeleccionado);
                if (BloqueBase)
                {
                    FVector PosActual = BloqueBase->GetActorLocation();
                    FVector NuevaPos = FVector(
                        PosActual.X,
                        PosActual.Y,
                        PosActual.Z + FMath::RandRange(200.f, 600.f) // Subir en Z
                    );
                    BloqueBase->IniciarMovimiento(NuevaPos, 50.0f);
                }


                Bloques.RemoveAt(IndiceAleatorio);

            }
        }
    }

}

void AGameModeLevel1::SpawnEnemigoSubterraneo()
{

    FVector BaseLocation = FVector(-4153.0f, -2371.0f, 20.0f); // Ubicacion inicial para el primer enemigo

    // Generar los enemigos
    for (int i = 0; i < 15; i++)
    {
        // Desviación aleatoria en el rango de -50 a 50 unidades para X y Y
        float PosicionProbableX = FMath::RandRange(-2950.0f, 2950.0f);
        float PosicionProbableY = FMath::RandRange(-2950.0f, 2950.0f);
        // Calcular la nueva ubicación basada en la última ubicación
        FVector Posicion = BaseLocation + FVector(PosicionProbableX, PosicionProbableY, 0.0f);
        // Spawn del enemigo
        AEnemigo* NewEnemigo = GetWorld()->SpawnActor<AEnemigo_Subterraneo>(AEnemigo_Subterraneo::StaticClass(), Posicion, FRotator::ZeroRotator);
        if (NewEnemigo) {
            NewEnemigo->SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
            UE_LOG(LogTemp, Warning, TEXT("Enemigos subterráneos generados: %d"), TodosLosEnemigos.Num());

        }
    }
}
void AGameModeLevel1::SpawnEnemigoAereo()
{

    FVector BaseLocation = FVector(-4153.0f, -2371.0f, 1000.0f);
    // Generar los enemigos
    for (int i = 0; i < 15; i++)
    {
        float PosicionProbableX = FMath::RandRange(-2950.0f, 2950.0f);
        float PosicionProbableY = FMath::RandRange(-2950.0f, 2950.0f);
        FVector Posicion = BaseLocation + FVector(PosicionProbableX, PosicionProbableY, 0.0f);
        AEnemigo* NewEnemigo = GetWorld()->SpawnActor<AEnemigo_Aereo>(AEnemigo_Aereo::StaticClass(), Posicion, FRotator::ZeroRotator);
        if (NewEnemigo) {
            NewEnemigo->SetActorScale3D(FVector(3.0f, 3.0f, 3.0f));
            TodosLosEnemigos.Add(NewEnemigo);
            UE_LOG(LogTemp, Warning, TEXT("Enemigos Aereos generados: %d"), TodosLosEnemigos.Num());

        }
    }
}



void AGameModeLevel1::SpawnEnemigoTerrestre()
{

    FVector BaseLocation = FVector(-4153.0f, -2371.0f, 20.0f);
    // Generar los enemigos
    for (int i = 0; i < 18; i++)
    {
        float PosicionProbableX = FMath::RandRange(-10950.0f, 10950.0f);
        float PosicionProbableY = FMath::RandRange(-10950.0f, 10950.0f);
        FVector Posicion = BaseLocation + FVector(PosicionProbableX, PosicionProbableY, 0.0f);
        AEnemigo* NewEnemigo = GetWorld()->SpawnActor<AEnemigo_Terrestre>(AEnemigo_Terrestre::StaticClass(), Posicion, FRotator::ZeroRotator);
        if (NewEnemigo) {
            NewEnemigo->SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
            TodosLosEnemigos.Add(NewEnemigo);
            UE_LOG(LogTemp, Warning, TEXT("Enemigos Terrestres generados: %d"), TodosLosEnemigos.Num());
        }
    }

}
void AGameModeLevel1::SpawnEnemigoAcuatico()
{
    FVector BaseLocation = FVector(3750.0f, 5230.0f, 0.0f);

    // Generar los enemigos
    for (int i = 0; i < 15; i++)
    {
        float PosicionProbableX = FMath::RandRange(-1950.0f, 1950.0f);
        float PosicionProbableY = FMath::RandRange(-1950.0f, 1950.0f);
        FVector Posicion = BaseLocation + FVector(PosicionProbableX, PosicionProbableY, 0.0f);
        AEnemigo* NewEnemigo = GetWorld()->SpawnActor<AEnemigo_Acuatico>(AEnemigo_Acuatico::StaticClass(), Posicion, FRotator::ZeroRotator);
        if (NewEnemigo) {
            NewEnemigo->SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
            TodosLosEnemigos.Add(NewEnemigo);
            UE_LOG(LogTemp, Warning, TEXT("Enemigos Acuaticos generados: %d"), TodosLosEnemigos.Num());
        }
    }

}