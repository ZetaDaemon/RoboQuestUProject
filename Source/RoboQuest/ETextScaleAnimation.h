#pragma once
#include "CoreMinimal.h"
#include "ETextScaleAnimation.generated.h"

UENUM(BlueprintType)
enum class ETextScaleAnimation : uint8 {
    SemiAuto,
    Auto,
    CriticalSemiAuto,
    CriticalAuto,
    Burn,
    Spark,
    CriticalSpark,
};

