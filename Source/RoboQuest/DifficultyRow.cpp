#include "DifficultyRow.h"

FDifficultyRow::FDifficultyRow() {
    this->Icon = NULL;
    this->EnemyHealthImpactPercentModifier = 0.00f;
    this->EnemyImpactPercentModifier = 0.00f;
    this->BossHealthPercentModifier = 0.00f;
    this->BossImpactPercentModifier = 0.00f;
    this->EnemyDamagePercentModifier = 0.00f;
    this->EnemySpeedModifier = 0.00f;
    this->BossSpeedModifier = 0.00f;
    this->AllyHealthPercentModifier = 0.00f;
    this->TrapDamagePercentModifier = 0.00f;
    this->TokenSpeedModifier = 0.00f;
    this->PickupLifetimeModifier = 0.00f;
    this->WorkerSpeedRatio = 0.00f;
    this->bOverridePermanentDamagePercent = false;
    this->PermanentDamagePercent = 0.00f;
    this->bOverrideBossPermanentDamagePercent = false;
    this->BossPermanentDamagePercent = 0.00f;
    this->bDamageBarIsLerping = false;
    this->WrenchesRewardOnEndLevel = 0;
    this->bMaxEliteLevel = false;
    this->NewGamePlusPoolID = 0;
    this->EnemyReplacementPercent = 0.00f;
    this->bIsInitiallyUnlocked = false;
    this->bUnlockAnotherOnVictory = false;
}

