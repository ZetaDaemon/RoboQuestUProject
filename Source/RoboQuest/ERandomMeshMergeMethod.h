#pragma once
#include "CoreMinimal.h"
#include "ERandomMeshMergeMethod.generated.h"

UENUM(BlueprintType)
enum class ERandomMeshMergeMethod : uint8 {
    MergeOnly,
    MergeAndOptimize,
    LastIndex,
};

