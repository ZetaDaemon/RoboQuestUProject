#pragma once
#include "CoreMinimal.h"
#include "EForceTileDirection.generated.h"

UENUM(BlueprintType)
enum class EForceTileDirection : uint8 {
    Random,
    Up,
    Right,
    Bot,
    Left,
    LastIndex,
};

