#pragma once
#include "CoreMinimal.h"
#include "EColorBlindType.generated.h"

UENUM(BlueprintType)
enum class EColorBlindType : uint8 {
    Deuteranope,
    Protanope,
    Tritanope,
    LastIndex,
};

