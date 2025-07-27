#include "ALaserBarProjectile.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AALaserBarProjectile::AALaserBarProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LaserBarRoot = CreateDefaultSubobject<USceneComponent>(TEXT("LaserBarRoot"));
    this->LaserBarRoot->SetupAttachment(RootComponent);
}


