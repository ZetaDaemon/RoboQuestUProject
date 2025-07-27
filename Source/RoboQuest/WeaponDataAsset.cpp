#include "WeaponDataAsset.h"

UWeaponDataAsset::UWeaponDataAsset() {
    this->DT_WeaponAffix = NULL;
    this->CoolingHighAnimationFPV[0] = NULL;
    this->CoolingHighAnimationFPV[1] = NULL;
    this->CoolingHighAnimationFPV[2] = NULL;
    this->CoolingHighAnimationFPV[3] = NULL;
    this->CoolingHighAnimationFPV[4] = NULL;
    this->CoolingLowAnimationFPV[0] = NULL;
    this->CoolingLowAnimationFPV[1] = NULL;
    this->CoolingLowAnimationFPV[2] = NULL;
    this->CoolingLowAnimationFPV[3] = NULL;
    this->CoolingLowAnimationFPV[4] = NULL;
    this->CoolingHighAnimationTPV[0] = NULL;
    this->CoolingHighAnimationTPV[1] = NULL;
    this->CoolingHighAnimationTPV[2] = NULL;
    this->CoolingHighAnimationTPV[3] = NULL;
    this->CoolingHighAnimationTPV[4] = NULL;
    this->CoolingSpeedRatioByAmmo = NULL;
    this->CoolingLowTriggerPercent = 0.50f;
    this->DT_WeaponMod = NULL;
    this->EnergizedReloadSpeed = 30.00f;
    this->EnergizedFirerate = 30.00f;
    this->EnergizedDuration = 6.00f;
    this->OverheatCommonSound = NULL;
    this->OverheatCommonHapticSound = NULL;
    this->OverheatCommonLoopSound = NULL;
}


