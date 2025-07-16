#pragma once
#include "CoreMinimal.h"
#include "EDoorWayBehaviour.generated.h"

UENUM(BlueprintType)
enum class EDoorWayBehaviour : uint8 {
    Normal,
    OneWay,
    TwoWays,
};

