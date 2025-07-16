#pragma once
#include "CoreMinimal.h"
#include "EWeaponAffixRarity.generated.h"

UENUM(BlueprintType)
enum class EWeaponAffixRarity : uint8 {
    Common,
    Rare,
    Elite,
    LastIndex,
};

