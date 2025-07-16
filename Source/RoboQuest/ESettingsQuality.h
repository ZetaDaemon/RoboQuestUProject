#pragma once
#include "CoreMinimal.h"
#include "ESettingsQuality.generated.h"

UENUM(BlueprintType)
enum class ESettingsQuality : uint8 {
    Low,
    Medium,
    High,
    Ultra,
    LastIndex,
};

