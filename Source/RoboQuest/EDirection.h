#pragma once
#include "CoreMinimal.h"
#include "EDirection.generated.h"

UENUM(BlueprintType)
enum class EDirection : uint8 {
    Up,
    Right,
    Bot,
    Left,
    LastIndex,
};

