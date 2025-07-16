#pragma once
#include "CoreMinimal.h"
#include "EDamageFeedabackType.generated.h"

UENUM(BlueprintType)
enum class EDamageFeedabackType : uint8 {
    Normal,
    Critical,
    Falloff,
    Burn,
    Shock,
    Ice,
};

