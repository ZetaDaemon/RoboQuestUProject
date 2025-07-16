#pragma once
#include "CoreMinimal.h"
#include "EController.generated.h"

UENUM(BlueprintType)
enum class EController : uint8 {
    XBox,
    PS4,
    Switch,
    PS5,
    LastIndex,
};

