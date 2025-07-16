#pragma once
#include "CoreMinimal.h"
#include "EGambleWeaponType.generated.h"

UENUM(BlueprintType)
enum class EGambleWeaponType : uint8 {
    Regular,
    Legendary,
    MAX,
};

