#pragma once
#include "CoreMinimal.h"
#include "ELevelTheme.generated.h"

UENUM(BlueprintType)
enum class ELevelTheme : uint8 {
    Canyon,
    Mine,
    Oasis,
    Road,
    Fields,
    Purification,
    Energy,
    Fusion,
    Air,
    LastIndex,
};

