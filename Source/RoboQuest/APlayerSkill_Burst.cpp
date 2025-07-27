#include "APlayerSkill_Burst.h"

UAPlayerSkill_Burst::UAPlayerSkill_Burst(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
    this->BurstFirerate = 0.00f;
    this->BurstAmount = 0;
}


