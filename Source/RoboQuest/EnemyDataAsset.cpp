#include "EnemyDataAsset.h"

UEnemyDataAsset::UEnemyDataAsset() {
    this->StaggerFX = NULL;
    this->StaggerLoopFX = NULL;
    this->StaggerSound = NULL;
    this->StaggerInvulnerabilityDelay = 0.35f;
    this->DelayStunRecovery = 0.75f;
    this->StunFX = NULL;
    this->StunInstantFX = NULL;
    this->StunSound = NULL;
    this->CurveStunRegeneration = NULL;
    this->CurveImpactRegeneration = NULL;
    this->CurveIceRegeneration = NULL;
    this->CurveBossStunRegeneration = NULL;
    this->CurveBossImpactRegeneration = NULL;
    this->CurveBossIceRegeneration = NULL;
    this->PlateDestructionFX = NULL;
    this->PlateDamageSpreadPercent = 35.00f;
    this->EmpowerDamageModifier = 50.00f;
    this->EmpowerSpeedModifier = 50.00f;
    this->StunDuration = 3.00f;
    this->FreezeDuration = 4.50f;
}


