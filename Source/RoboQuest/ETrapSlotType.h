#pragma once
#include "CoreMinimal.h"
#include "ETrapSlotType.generated.h"

UENUM(BlueprintType)
enum class ETrapSlotType : uint8 {
    Random,
    Laser,
    MAX,
};

