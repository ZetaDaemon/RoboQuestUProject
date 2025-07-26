#include "AInfiniteBossPoint.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ArrowComponent -FallbackName=ArrowComponent

AAInfiniteBossPoint::AAInfiniteBossPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpawnDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnDirection"));
    this->SpawnLevel = 1;
    this->bInvulnerable = false;
    this->SpawnedEnemy = NULL;
    this->GameStateRef = NULL;
    this->SpawnDirection->SetupAttachment(RootComponent);
}


