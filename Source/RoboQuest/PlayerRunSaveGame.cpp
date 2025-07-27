#include "PlayerRunSaveGame.h"

FPlayerRunSaveGame::FPlayerRunSaveGame() {
    this->PlayerLevel = 0;
    this->HealthReliquat = 0.00f;
    this->DamageBarValue = 0.00f;
    this->ExperienceReliquat = 0.00f;
    this->ItemRerollPoint = 0;
    this->GambleGarryUseAmount = 0;
    this->Powercells = 0;
    this->InRunPowercells = 0;
    this->InRunWrenches = 0;
    this->CustomCurrencyValues[0] = 0;
    this->CustomCurrencyValues[1] = 0;
    this->HighestDamageDeal = 0;
    this->TotalDamageDealt = 0;
    this->TotalDamageTaken = 0;
    this->EnemyTakedown = 0;
    this->InRunDatalog = 0;
    this->ExtraLife = 0;
    this->SuperbotCurrentUpgradeOnEatWeapon = 0;
}

