#pragma once
#include "CoreMinimal.h"
#include "ESessionRegion.generated.h"

UENUM(BlueprintType)
enum class ESessionRegion : uint8 {
    Europe,
    Asia,
    Oceania,
    Africa,
    NorthAmerica,
    SouthAmerica,
    All,
    LastIndex,
};

