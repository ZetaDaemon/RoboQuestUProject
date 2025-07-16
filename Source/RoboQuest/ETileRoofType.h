#pragma once
#include "CoreMinimal.h"
#include "ETileRoofType.generated.h"

UENUM(BlueprintType)
enum class ETileRoofType : uint8 {
    Cross,
    Turn,
    T,
    StraightLine,
    DeadEnd,
    LastIndex,
};

