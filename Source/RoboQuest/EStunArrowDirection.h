#pragma once
#include "CoreMinimal.h"
#include "EStunArrowDirection.generated.h"

UENUM(BlueprintType)
enum class EStunArrowDirection : uint8 {
    Right,
    Left,
    Up,
    Down,
    MAX,
};

