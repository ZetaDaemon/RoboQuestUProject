#pragma once
#include "CoreMinimal.h"
#include "EBigPointType.generated.h"

UENUM(BlueprintType)
enum class EBigPointType : uint8 {
    LevelGeneratorOnly,
    InfiniteRunOnly,
    Both,
};

