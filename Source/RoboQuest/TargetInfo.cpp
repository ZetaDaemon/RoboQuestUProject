#include "TargetInfo.h"

FTargetInfo::FTargetInfo() {
    this->Target = NULL;
    this->HitActor = NULL;
    this->Distance = 0.00f;
    this->YawDifference = 0.00f;
    this->AIState = EAIState::Idle;
}

