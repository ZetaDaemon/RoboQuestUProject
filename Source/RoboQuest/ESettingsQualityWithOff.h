#pragma once
#include "CoreMinimal.h"
#include "ESettingsQualityWithOff.generated.h"

UENUM(BlueprintType)
enum class ESettingsQualityWithOff : uint8 {
    Off,
    Low,
    Medium,
    High,
    Ultra,
    LastIndex,
};

