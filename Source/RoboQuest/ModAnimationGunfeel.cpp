#include "ModAnimationGunfeel.h"

FModAnimationGunfeel::FModAnimationGunfeel() {
    this->Animation = NULL;
    this->bUsePrimaryGunFeel = false;
    this->UpRecoilPerShot = 0.00f;
    this->RecoilUpSpeed = 0.00f;
    this->RecoilUpMultiplierPerSecond = 0.00f;
    this->MinRecoilUpRatio = 0.00f;
    this->LateralRecoilPerShot = 0.00f;
    this->LateralRecoilSpeed = 0.00f;
    this->RecoilRecoverySpeed = 0.00f;
    this->RecoilRecoveryMultiplierPerSecond = 0.00f;
    this->MaxRecoilRecoverySpeed = 0.00f;
}

