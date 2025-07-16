#pragma once
#include "CoreMinimal.h"
#include "ERandomLuck.generated.h"

UENUM(BlueprintType)
enum class ERandomLuck : uint8 {
    Low,
    Mid,
    High,
    LastIndex,
};

