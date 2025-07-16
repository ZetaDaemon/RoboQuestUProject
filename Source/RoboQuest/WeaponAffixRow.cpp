#include "WeaponAffixRow.h"

FWeaponAffixRow::FWeaponAffixRow() {
    this->LoadedAffix = NULL;
    this->bEnchantedAffix = false;
    this->Rarity = EWeaponAffixRarity::Common;
    this->bActivate = false;
    this->PerfumerIcon = EPerfumerIcon::Default;
}

