#include "AShootingRangeLight.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent

AAShootingRangeLight::AAShootingRangeLight(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->Index = 0;
    this->ActivationDelay = 0.00f;
    this->GameStateRef = NULL;
    this->Mesh->SetupAttachment(RootComponent);
}

void AAShootingRangeLight::OnEndTimerActivation() {
}

AAGameState* AAShootingRangeLight::GetGameStateRef() {
    return NULL;
}

void AAShootingRangeLight::DeactivateLight_Implementation() {
}

void AAShootingRangeLight::ActivateLight_Implementation() {
}


