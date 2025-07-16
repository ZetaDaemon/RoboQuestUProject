#pragma once
#include "CoreMinimal.h"
#include "EInfiniteLayoutCategory.generated.h"

UENUM(BlueprintType)
enum class EInfiniteLayoutCategory : uint8 {
    Start,
    Level,
    Boss,
    MAX,
};

