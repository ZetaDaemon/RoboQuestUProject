#pragma once
#include "CoreMinimal.h"
#include "ECrosshairMode.generated.h"

UENUM(BlueprintType)
enum class ECrosshairMode : uint8 {
    Roboquest,
    Cross,
    Point,
    LastIndex,
};

