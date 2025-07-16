#pragma once
#include "CoreMinimal.h"
#include "EBubbleTailLocation.generated.h"

UENUM(BlueprintType)
enum class EBubbleTailLocation : uint8 {
    NoTail,
    BottomRight,
    TopRight,
    BottomLeft,
    TopLeft,
    BottomCenter,
    TopCenter,
    MAX,
};

