#pragma once
#include "CoreMinimal.h"
#include "EPickupLocation.generated.h"

UENUM(BlueprintType)
enum class EPickupLocation : uint8 {
    Entering,
    Exiting,
};

