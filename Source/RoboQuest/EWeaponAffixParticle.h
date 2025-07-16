#pragma once
#include "CoreMinimal.h"
#include "EWeaponAffixParticle.generated.h"

UENUM(BlueprintType)
enum class EWeaponAffixParticle : uint8 {
    Base,
    Common,
    Rare,
    Epic,
    Legendary,
    LastIndex,
};

