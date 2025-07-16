#pragma once
#include "CoreMinimal.h"
#include "EModifierStatType.generated.h"

UENUM(BlueprintType)
enum class EModifierStatType : uint8 {
    Flat,
    Percent,
};

