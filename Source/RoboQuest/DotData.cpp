#include "DotData.h"

FDotData::FDotData() {
    this->TickFrequency = 0.00f;
    this->TickAmount = 0;
    this->ImpactRatio = 0.00f;
    this->StunImpactRatio = 0.00f;
    this->bInstantTick = false;
    this->DamageType = EDamageType::Bullet;
    this->GameplayTag = EGameplayTags::Explosive;
    this->bApplyStatus = false;
    this->Status = EStatus::Energized;
    this->RagdollType = EKillRagdollType::Low;
}

