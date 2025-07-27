#include "ASlot.h"
#include "Components/BoxComponent.h"

AASlot::AASlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
    this->RootBox = (UBoxComponent*)RootComponent;
    this->DynamicHoloMaterial = NULL;
    this->HoloMaterial = NULL;
    this->DisplayActor = NULL;
}

void AASlot::TriggerDestroy() {
}


