#pragma once
#include "CoreMinimal.h"
#include "EConsole.generated.h"

UENUM(BlueprintType)
enum class EConsole : uint8 {
    XBoxOneS,
    XBoxOneX,
    XBoxSerieS,
    XBoxSerieX,
    PS4,
    PS5,
    MAX,
};

