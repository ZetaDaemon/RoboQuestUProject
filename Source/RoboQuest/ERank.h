#pragma once
#include "CoreMinimal.h"
#include "ERank.generated.h"

UENUM(BlueprintType)
enum class ERank : uint8 {
    S,
    A,
    B,
    C,
    D,
    E,
    LastIndex,
};

