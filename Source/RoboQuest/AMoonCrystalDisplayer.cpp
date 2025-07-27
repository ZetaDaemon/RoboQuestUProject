#include "AMoonCrystalDisplayer.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAMoonCrystalDisplayer::AAMoonCrystalDisplayer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
    this->SceneRoot = (USceneComponent*)RootComponent;
    this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->LocalPlayerControllerRef = NULL;
    this->LocalPlayerCharacterRef = NULL;
    this->GameInstanceRef = NULL;
    this->GameStateRef = NULL;
    this->Mesh->SetupAttachment(RootComponent);
}

AAPlayerController* AAMoonCrystalDisplayer::GetLocalPlayerControllerRef() const {
    return NULL;
}

ACharacter_Player* AAMoonCrystalDisplayer::GetLocalPlayerCharacterRef() const {
    return NULL;
}

AAGameState* AAMoonCrystalDisplayer::GetGameStateRef() const {
    return NULL;
}

UAGameInstance* AAMoonCrystalDisplayer::GetGameInstanceRef() const {
    return NULL;
}


