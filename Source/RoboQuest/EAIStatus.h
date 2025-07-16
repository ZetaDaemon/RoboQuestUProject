#pragma once
#include "CoreMinimal.h"
#include "EAIStatus.generated.h"

UENUM(BlueprintType)
enum class EAIStatus : uint8 {
    Burn,
    Stun,
    Marked,
    Frozen,
    Staggered,
    Focused,
    Empower,
    Shielded,
    LastIndex,
};

