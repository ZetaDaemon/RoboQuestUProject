#pragma once
#include "CoreMinimal.h"
#include "ERangeCategory.generated.h"

UENUM(BlueprintType)
enum class ERangeCategory : uint8 {
    Close,
    Mid,
    Long,
    Out,
};

