#include "ARandomizer.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AARandomizer::AARandomizer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RandomRoot"));
    this->RandomRoot = (USceneComponent*)RootComponent;
    this->Luck = ERandomLuck::Mid;
}


