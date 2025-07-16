#pragma once
#include "CoreMinimal.h"
#include "EStatSuffix.generated.h"

UENUM(BlueprintType)
enum class EStatSuffix : uint8 {
    None,
    Percent,
    Second,
    Meter,
    LastIndex,
};

