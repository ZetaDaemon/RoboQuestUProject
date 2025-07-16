#pragma once
#include "CoreMinimal.h"
#include "EBumpIntensity.generated.h"

UENUM(BlueprintType)
enum class EBumpIntensity : uint8 {
    None,
    Low,
    Medium,
    High,
    RocketJump,
    Extreme,
    MiniCricket,
    LastIndex,
};

