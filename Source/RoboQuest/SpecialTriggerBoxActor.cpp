#include "SpecialTriggerBoxActor.h"
#include "SpecialTriggerBoxComponent.h"

ASpecialTriggerBoxActor::ASpecialTriggerBoxActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<USpecialTriggerBoxComponent>(TEXT("CollisionComp"))) {
}


