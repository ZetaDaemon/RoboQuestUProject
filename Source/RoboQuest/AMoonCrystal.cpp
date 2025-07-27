#include "AMoonCrystal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAMoonCrystal::AAMoonCrystal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BaseTop = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseTop"));
    this->BaseBottom = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseBottom"));
    this->Crystal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Crystal"));
    this->BaseTop->SetupAttachment(RootComponent);
    this->BaseBottom->SetupAttachment(RootComponent);
    this->Crystal->SetupAttachment(RootComponent);
}

void AAMoonCrystal::OnCrystalMeshLoaded() {
}


