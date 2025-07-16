#pragma once
#include "CoreMinimal.h"
#include "EElement.generated.h"

UENUM(BlueprintType)
enum class EElement : uint8 {
    Burn,
    Ice,
    Shock,
    LastIndex,
};

