#pragma once
#include "CoreMinimal.h"
#include "EWeaponRank.generated.h"

UENUM(BlueprintType)
enum class EWeaponRank : uint8 {
    Common,
    Uncommon,
    Rare,
    Epic,
    Legendary,
};

