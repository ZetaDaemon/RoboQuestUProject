#pragma once
#include "CoreMinimal.h"
#include "EProjectileExecutionOrder.generated.h"

UENUM(BlueprintType)
enum class EProjectileExecutionOrder : uint8 {
    Ordered,
    Random,
};

