#pragma once
#include "CoreMinimal.h"
#include "EWeaponAffixType.generated.h"

UENUM(BlueprintType)
enum class EWeaponAffixType : uint8 {
    Base,
    Random,
    Enchanted,
    Corrupted,
    LastIndex,
};

