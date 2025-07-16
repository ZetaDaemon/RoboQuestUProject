#pragma once
#include "CoreMinimal.h"
#include "EWeaponProcType.generated.h"

UENUM(BlueprintType)
enum class EWeaponProcType : uint8 {
    Heal,
    Critical,
    Cooldown,
    Damage,
    Corrupted,
    LastIndex,
};

