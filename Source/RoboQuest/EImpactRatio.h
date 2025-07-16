#pragma once
#include "CoreMinimal.h"
#include "EImpactRatio.generated.h"

UENUM(BlueprintType)
enum class EImpactRatio : uint8 {
    None,
    VeryLow,
    Low,
    Middle,
    High,
    VeryHigh,
    Incredible,
    LastIndex,
};

