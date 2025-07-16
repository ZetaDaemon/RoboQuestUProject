#pragma once
#include "CoreMinimal.h"
#include "EGraphicQualityPreset.generated.h"

UENUM(BlueprintType)
enum class EGraphicQualityPreset : uint8 {
    Custom,
    Low,
    Medium,
    High,
    Ultra,
    Preset,
    LastIndex,
};

