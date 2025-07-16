#pragma once
#include "CoreMinimal.h"
#include "EIntensity.generated.h"

UENUM(BlueprintType)
enum class EIntensity : uint8 {
    None,
    Low,
    Medium,
    High,
    LastIndex,
};

