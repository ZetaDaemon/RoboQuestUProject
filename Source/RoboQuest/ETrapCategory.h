#pragma once
#include "CoreMinimal.h"
#include "ETrapCategory.generated.h"

UENUM(BlueprintType)
enum class ETrapCategory : uint8 {
    Wall,
    Ground,
    LastIndex,
};

