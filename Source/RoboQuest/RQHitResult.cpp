#include "RQHitResult.h"

FRQHitResult::FRQHitResult() {
    this->HitEvent = EHitEvent::Hit;
    this->HitBoneType = EBonesType::None;
    this->HitTeam = ETeam::Player;
    this->BounceAmount = 0;
    this->RicochetAmount = 0;
    this->PierceAmount = 0;
    this->HitAmount = 0;
}

