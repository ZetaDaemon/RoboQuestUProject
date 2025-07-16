#pragma once
#include "CoreMinimal.h"
#include "ETextColorAnimation.generated.h"

UENUM(BlueprintType)
enum class ETextColorAnimation : uint8 {
    None,
    Critical,
    Burn,
    CriticalBurn,
    Ice,
    CriticalIce,
    Shock,
    CriticalShock,
};

