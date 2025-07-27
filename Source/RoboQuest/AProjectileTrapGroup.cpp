#include "AProjectileTrapGroup.h"
#include "ETrapType.h"

AAProjectileTrapGroup::AAProjectileTrapGroup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETrapType::Projectile;
    this->ExecutionOrder = EProjectileExecutionOrder::Ordered;
    this->bAvoidSamePatternTwice = false;
    this->PrevisionalPatternCount = 2;
    this->GameInstanceRef = NULL;
}


