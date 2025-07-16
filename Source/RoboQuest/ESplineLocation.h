#pragma once
#include "CoreMinimal.h"
#include "ESplineLocation.generated.h"

UENUM(BlueprintType)
enum class ESplineLocation : uint8 {
    Entering,
    Exiting,
    Both,
};

