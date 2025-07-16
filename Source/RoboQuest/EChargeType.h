#pragma once
#include "CoreMinimal.h"
#include "EChargeType.generated.h"

UENUM(BlueprintType)
enum class EChargeType : uint8 {
    Warmup,
    Charged,
    FullCharged,
    Scope,
};

