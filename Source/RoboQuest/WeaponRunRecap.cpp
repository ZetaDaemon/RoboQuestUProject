#include "WeaponRunRecap.h"

FWeaponRunRecap::FWeaponRunRecap() {
    this->Level = 0;
    this->Rarity = EWeaponColor::Base;
    this->Damage = 0.00f;
    this->DamageAmount = 0;
    this->FireRate = 0.00f;
    this->bAreaOfEffect = false;
    this->Range = 0.00f;
    this->Crit = 0.00f;
    this->bSecondaryScope = false;
    this->SecondaryStack = 0;
    this->SecondaryCooldown = 0;
}

