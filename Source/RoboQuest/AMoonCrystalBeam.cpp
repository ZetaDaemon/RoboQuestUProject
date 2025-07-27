#include "AMoonCrystalBeam.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAMoonCrystalBeam::AAMoonCrystalBeam(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->Beam = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Beam"));
    this->bIsCrystalActive = false;
    this->GameInstanceRef = NULL;
    this->GameStateRef = NULL;
    this->Beam->SetupAttachment(RootComponent);
}


void AAMoonCrystalBeam::OnBeamMaterialLoaded() {
}


