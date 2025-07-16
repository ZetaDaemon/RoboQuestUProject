#pragma once
#include "CoreMinimal.h"
#include "EWorkerSplineLevelRestriction.generated.h"

UENUM(BlueprintType)
enum class EWorkerSplineLevelRestriction : uint8 {
    OnlyInRegularLevel,
    OnlyInCorruptedLevel,
    Both,
};

