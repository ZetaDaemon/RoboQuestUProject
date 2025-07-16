#pragma once
#include "CoreMinimal.h"
#include "EGarryReward.generated.h"

UENUM(BlueprintType)
enum class EGarryReward : uint8 {
    Nothing,
    CompendiumCard,
    Wrench,
    Powercell,
    Powercell2,
    Powercell3,
    PerkReroll,
    CommonItem,
    RareItem,
    LegendaryItem,
    Upgrade,
    WeaponToken,
    LegendaryWeapon,
    Weapon,
    CrystalPowder,
    LastIndex,
};

