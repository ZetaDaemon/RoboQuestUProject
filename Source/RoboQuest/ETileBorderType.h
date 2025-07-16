#pragma once
#include "CoreMinimal.h"
#include "ETileBorderType.generated.h"

UENUM(BlueprintType)
enum class ETileBorderType : uint8 {
    TurnIn,
    TurnOut,
    T,
    StraightLine,
    DeadEnd,
    Block,
    DoubleSided,
    LastIndex,
};

