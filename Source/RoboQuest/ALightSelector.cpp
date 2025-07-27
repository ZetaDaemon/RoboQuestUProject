#include "ALightSelector.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AALightSelector::AALightSelector(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->CurrentPostProcessActor = NULL;
    this->bForceRotation = false;
    this->ForcedYaw = 0.00f;
    this->GameInstanceRef = NULL;
    this->GameStateRef = NULL;
}

FName AALightSelector::UpdateLightScenario() {
    return NAME_None;
}

void AALightSelector::TemporarilyDisableAllBlendables() {
}

void AALightSelector::SetLightScenario(const FName& LightScenarioName) {
}

void AALightSelector::RotateTo(float YawAngle) {
}

void AALightSelector::RotateCounterClockwise() {
}

void AALightSelector::RotateClockwise() {
}

void AALightSelector::ReEnableAllBlendables() {
}

void AALightSelector::OnPostProcessClassLoaded(FName LightScenarioRowName, bool bSetCurrent) {
}




bool AALightSelector::NeedsFlashLight() const {
    return false;
}

FName AALightSelector::IncrementLightScenario() {
    return NAME_None;
}

AAGameState* AALightSelector::GetGameStateRef() const {
    return NULL;
}

UAGameInstance* AALightSelector::GetGameInstanceRef() const {
    return NULL;
}

FName AALightSelector::DecrementLightScenario() {
    return NAME_None;
}


