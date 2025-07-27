#include "AEnemySkill.h"

UAEnemySkill::UAEnemySkill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
}


