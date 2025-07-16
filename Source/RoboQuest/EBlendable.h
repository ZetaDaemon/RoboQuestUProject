#pragma once
#include "CoreMinimal.h"
#include "EBlendable.generated.h"

UENUM(BlueprintType)
enum class EBlendable : uint8 {
    GenericOutline,
    Damaged,
    HeightSaturation,
    FogSaturation,
    LowLife,
    IrisArena,
};

