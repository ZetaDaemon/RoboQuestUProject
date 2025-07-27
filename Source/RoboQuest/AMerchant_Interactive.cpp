#include "AMerchant_Interactive.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ChildActorComponent -FallbackName=ChildActorComponent

AAMerchant_Interactive::AAMerchant_Interactive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InteractChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("InteractChildActor"));
    this->InteractChildActor->SetupAttachment(RootComponent);
}


