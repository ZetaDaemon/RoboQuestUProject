#pragma once
#include "CoreMinimal.h"
#include "EWeaponCategory.generated.h"

UENUM(BlueprintType)
enum class EWeaponCategory : uint8 {
    Assault,
    Precision,
    Technology,
    Demolition,
    CloseCombat,
    LastIndex,
};

