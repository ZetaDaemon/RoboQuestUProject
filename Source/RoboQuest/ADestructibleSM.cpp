#include "ADestructibleSM.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AADestructibleSM::AADestructibleSM(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DestructibleSM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DestructibleSM"));
    this->DestructibleSM->SetupAttachment(RootComponent);
}


