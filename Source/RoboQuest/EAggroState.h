#pragma once
#include "CoreMinimal.h"
#include "EAggroState.generated.h"

UENUM(BlueprintType)
enum class EAggroState : uint8 {
    Guard,
    Aggressive,
};

