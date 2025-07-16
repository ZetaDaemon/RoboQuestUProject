#pragma once
#include "CoreMinimal.h"
#include "EDot.generated.h"

UENUM(BlueprintType)
enum class EDot : uint8 {
    Burn,
    Shock,
    Mark,
    Ice,
    LastIndex,
};

