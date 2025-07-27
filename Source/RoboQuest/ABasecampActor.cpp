#include "ABasecampActor.h"

AABasecampActor::AABasecampActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LocalPlayerControllerRef = NULL;
    this->LocalPlayerCharacterRef = NULL;
    this->GameInstanceRef = NULL;
    this->GameStateRef = NULL;
}

AAPlayerController* AABasecampActor::GetLocalPlayerControllerRef() const {
    return NULL;
}

ACharacter_Player* AABasecampActor::GetLocalPlayerCharacterRef() const {
    return NULL;
}

AAGameState* AABasecampActor::GetGameStateRef() const {
    return NULL;
}

UAGameInstance* AABasecampActor::GetGameInstanceRef() const {
    return NULL;
}


