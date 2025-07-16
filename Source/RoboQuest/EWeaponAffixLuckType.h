#pragma once
#include "CoreMinimal.h"
#include "EWeaponAffixLuckType.generated.h"

UENUM(BlueprintType)
enum class EWeaponAffixLuckType : uint8 {
    Fantastic,
    Wonderfull,
    Legendary,
    LastIndex,
};

