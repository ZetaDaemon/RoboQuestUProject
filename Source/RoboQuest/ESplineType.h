#pragma once
#include "CoreMinimal.h"
#include "ESplineType.generated.h"

UENUM(BlueprintType)
enum class ESplineType : uint8 {
    Environment,
    Worker,
    Riding,
    LastIndex,
};

