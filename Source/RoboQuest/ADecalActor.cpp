#include "ADecalActor.h"
#include "CustomDecalComponent.h"

AADecalActor::AADecalActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UCustomDecalComponent>(TEXT("NewDecalComponent"))) {
}


