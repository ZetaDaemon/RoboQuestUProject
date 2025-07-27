#include "AISkillDataAsset.h"

UAISkillDataAsset::UAISkillDataAsset() {
    this->PreshootOverheadFX = NULL;
    this->PreshootOverheadFXSpawnDelay = 0.15f;
    this->PreshootPitchCurve = NULL;
    this->PreshootVolumeCurve = NULL;
    this->SlowPreshootRatio = 0.12f;
    this->SlowPreshootRatioAfterDuration = 0.65f;
    this->SlowPreshootRange = 850.00f;
    this->SlowPreshootDuration = 1.25f;
}


