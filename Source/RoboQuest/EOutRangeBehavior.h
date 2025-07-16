#pragma once
#include "CoreMinimal.h"
#include "EOutRangeBehavior.generated.h"

UENUM(BlueprintType)
enum class EOutRangeBehavior : uint8 {
    None,
    Destroy,
    Teleport,
};

