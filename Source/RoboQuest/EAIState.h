#pragma once
#include "CoreMinimal.h"
#include "EAIState.generated.h"

UENUM(BlueprintType)
enum class EAIState : uint8 {
    Idle,
    Attacking,
    Seeking,
    Stunned,
    Staggered,
    AllySightBlock,
    Dead,
};

