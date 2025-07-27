#include "AShootingRangeButton.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAShootingRangeButton::AAShootingRangeButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh"));
    this->bReplicateInteraction = false;
    this->Index = 0;
    this->Cooldown = 2.00f;
    this->ButtonMesh->SetupAttachment(RootComponent);
}


void AAShootingRangeButton::OnEndCooldown() {
}


