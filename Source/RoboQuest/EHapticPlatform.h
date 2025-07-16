#pragma once
#include "CoreMinimal.h"
#include "EHapticPlatform.generated.h"

UENUM(BlueprintType)
enum class EHapticPlatform : uint8 {
    PC,
    XBoxOne,
    XBoxSerie,
    PS4,
    PS5,
    LastIndex,
};

