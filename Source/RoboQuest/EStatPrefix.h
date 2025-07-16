#pragma once
#include "CoreMinimal.h"
#include "EStatPrefix.generated.h"

UENUM(BlueprintType)
enum class EStatPrefix : uint8 {
    None,
    Increase,
    Decrease,
    LastIndex,
};

