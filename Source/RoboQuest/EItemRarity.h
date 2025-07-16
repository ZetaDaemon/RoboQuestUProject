#pragma once
#include "CoreMinimal.h"
#include "EItemRarity.generated.h"

UENUM(BlueprintType)
enum class EItemRarity : uint8 {
    Common,
    Rare,
    Epic,
    Legendary,
    Corrupted,
    LastIndex,
};

