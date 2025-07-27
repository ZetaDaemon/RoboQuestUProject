#include "AWallTurretSlot.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent

AAWallTurretSlot::AAWallTurretSlot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HoloMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HoloMesh"));
    this->HoloMesh->SetupAttachment(RootComponent);
}


