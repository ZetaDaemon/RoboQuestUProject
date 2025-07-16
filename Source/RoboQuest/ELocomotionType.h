#pragma once
#include "CoreMinimal.h"
#include "ELocomotionType.generated.h"

UENUM(BlueprintType)
enum class ELocomotionType : uint8 {
    FootstepRun,
    FootstepSprint,
    FootstepScuff,
    FootstepJumpStart,
    LandLow,
    LandMid,
    LandHigh,
    LastIndex,
};

