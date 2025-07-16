#pragma once
#include "CoreMinimal.h"
#include "EItemCategory.generated.h"

UENUM(BlueprintType)
enum class EItemCategory : uint8 {
    Assault,
    Precision,
    Technology,
    Demolition,
    CloseCombat,
    Class,
    Utility,
    Subclass,
    LastIndex,
};

