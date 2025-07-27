#include "InGameStateDataAsset.h"

UInGameStateDataAsset::UInGameStateDataAsset() {
    this->DT_EnemyDeath = NULL;
    this->DT_GameTips = NULL;
    this->PickupPoolAmount[0] = 0;
    this->PickupPoolAmount[1] = 0;
    this->PickupPoolAmount[2] = 0;
    this->PickupPoolAmount[3] = 0;
    this->PickupPoolAmount[4] = 0;
    this->PickupPoolAmount[5] = 0;
    this->PickupPoolAmount[6] = 0;
    this->PickupPoolAmount[7] = 0;
    this->PickupPoolAmount[8] = 0;
    this->PickupPoolAmount[9] = 0;
    this->PickupPoolAmount[10] = 0;
    this->MultiplayerTimePickupValue = 1.20f;
    this->CurveHealthPickup = NULL;
    this->bDisableWeaponPickupLoot = false;
    this->WeaponPickupLootValue = 22;
    this->MultiplayerWeaponPickupLootValue = 26;
    this->InteractiveItemClass = NULL;
}


