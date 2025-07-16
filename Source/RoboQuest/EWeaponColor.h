#pragma once
#include "CoreMinimal.h"
#include "EWeaponColor.generated.h"

UENUM(BlueprintType)
enum class EWeaponColor : uint8 {
    Base,
    Common,
    Rare,
    Epic,
    Legendary,
    LastIndex,
};

