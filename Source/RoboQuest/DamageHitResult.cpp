#include "DamageHitResult.h"

FDamageHitResult::FDamageHitResult() {
    this->Damage = 0.00f;
    this->ImpactForce = 0.00f;
    this->FalloffRatio = 0.00f;
    this->BoneType = EBonesType::None;
}

