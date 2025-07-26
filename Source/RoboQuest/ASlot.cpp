#include "ASlot.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BoxComponent -FallbackName=BoxComponent

AASlot::AASlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
    this->RootBox = (UBoxComponent*)RootComponent;
    this->DynamicHoloMaterial = NULL;
    this->HoloMaterial = NULL;
    this->DisplayActor = NULL;
}

void AASlot::TriggerDestroy() {
}


