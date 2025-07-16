#include "ClientDamageInfo.h"

FClientDamageInfo::FClientDamageInfo() {
    this->Actor = NULL;
    this->DamageAmount = 0.00f;
    this->ImpactForceAmount = 0.00f;
    this->IceRatio = 0.00f;
    this->ShockRatio = 0.00f;
    this->GameplayTags = 0;
}

