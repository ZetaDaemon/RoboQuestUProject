#include "AISkillRow.h"

FAISkillRow::FAISkillRow() {
    this->TargetDirection = ETargetDirection::Target;
    this->bPredictMovement = false;
    this->MaxPredictDuration = 0.00f;
    this->bPredictZVelocity = false;
    this->HitAmount = 0;
    this->UseAmount = 0;
    this->FireRate = 0.00f;
    this->bSpreadPatternWithMuzzleIndex = false;
    this->bSpreadPatternWithUseAmount = false;
    this->PreshootDuration = 0.00f;
    this->bSlowPreshootInClose = false;
    this->RecoveryDuration = 0.00f;
    this->bCustomSpread = false;
    this->bCustomMuzzle = false;
    this->MuzzleType = ESkillMuzzleType::All;
    this->bShowDebugTrace = false;
    this->TokenRule = ETokenRule::None;
    this->bCancelIfTurnAround = false;
    this->bRotateBeforePreshoot = false;
    this->bCanRotate = false;
    this->AIMSpeedRatio = 0.00f;
    this->MaxUseAmount = 0;
    this->Cooldown = 0.00f;
    this->bFlatDistance = false;
    this->ArcDistance = 0.00f;
    this->bOverrideSound = false;
    this->bLoopSound = false;
    this->LoadedStartPreshoot = NULL;
    this->LoadedLoopPreshoot = NULL;
    this->LoopPreshootFadeOutDelay = 0.00f;
    this->LoadedUseSound = NULL;
    this->LoadedLoopSound = NULL;
    this->LoadedStopSound = NULL;
    this->LoadedPreshoot = NULL;
    this->LoadedShoot = NULL;
    this->ShootPlayrate = 0.00f;
    this->LoadedOtherMultiShoot = NULL;
    this->OtherMultiShootPlayrate = 0.00f;
}

