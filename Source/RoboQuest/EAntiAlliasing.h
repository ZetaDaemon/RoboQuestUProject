#pragma once
#include "CoreMinimal.h"
#include "EAntiAlliasing.generated.h"

UENUM(BlueprintType)
enum class EAntiAlliasing : uint8 {
    Off,
    FXAA,
    TemporalAA,
    LastIndex,
};

