#include "ABullFlyAnimInstance.h"

UABullFlyAnimInstance::UABullFlyAnimInstance() {
    this->bIsCharging = false;
    this->bHaveHitPlayer = false;
    this->bChargeLoopToEndCharge = false;
    this->bChargeLoopToEndChargeHit = false;
    this->bStartChargeToChargeLoop = false;
    this->bEndChargeToIdle = false;
    this->bEndChargeHitToIdle = false;
}

void UABullFlyAnimInstance::SetIsCharging(bool bCharging) {
}

void UABullFlyAnimInstance::SetHaveHitPlayer(bool bHitPlayer) {
}


