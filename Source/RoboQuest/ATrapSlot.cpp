#include "ATrapSlot.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AATrapSlot::AATrapSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->LaserView = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserView"));
    this->Type = ETrapSlotType::Random;
    this->Location = ETrapSlotLocation::Anywhere;
    this->Mesh->SetupAttachment(RootComponent);
    this->LaserView->SetupAttachment(RootComponent);
}


