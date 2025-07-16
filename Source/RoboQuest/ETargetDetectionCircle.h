#pragma once
#include "CoreMinimal.h"
#include "ETargetDetectionCircle.generated.h"

UENUM(BlueprintType)
enum class ETargetDetectionCircle : uint8 {
    Crosshair,
    AimAssist,
    SensitivitySlow,
    Magnetism,
    ForwardDetection,
    Grapple,
    LastIndex,
};

