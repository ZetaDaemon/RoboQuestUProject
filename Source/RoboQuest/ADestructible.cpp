#include "ADestructible.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AADestructible::AADestructible(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->bHitFeedback = false;
    this->Health = 1.00f;
    this->DeathSound = NULL;
    this->LevelGeneratorRef = NULL;
    this->GameStateRef = NULL;
}

AALevelGenerator* AADestructible::GetLevelGeneratorRef() const {
    return NULL;
}

AAGameState* AADestructible::GetGameStateRef() const {
    return NULL;
}


