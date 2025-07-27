#include "AHoleSpawnerSlot.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAHoleSpawnerSlot::AAHoleSpawnerSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HoloMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HoloMesh"));
    this->SpawnLevel = 1;
    this->GameStateRef = NULL;
    this->HoloMesh->SetupAttachment(RootComponent);
}

AAGameState* AAHoleSpawnerSlot::GetGameStateRef() const {
    return NULL;
}


