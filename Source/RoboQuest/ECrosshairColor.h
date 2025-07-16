#pragma once
#include "CoreMinimal.h"
#include "ECrosshairColor.generated.h"

UENUM(BlueprintType)
enum class ECrosshairColor : uint8 {
    Roboquest,
    White,
    Green,
    YellowGreen,
    GreenYellow,
    Cyan,
    Pink,
    Red,
    Blue,
    LastIndex,
};

