#pragma once
#include "CoreMinimal.h"
#include "EHUDAnimation.generated.h"

UENUM(BlueprintType)
enum class EHUDAnimation : uint8 {
    None,
    Idle,
    RunForward,
    RunBackward,
    RunLeft,
    RunRight,
    Sprint,
    StartJump,
    LandLow,
    LandMid,
    LandHigh,
    Aerial,
    SlashRight,
    SlashLeft,
    SmallShake,
    StrongShake,
};

