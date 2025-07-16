#pragma once
#include "CoreMinimal.h"
#include "ESprintMode.generated.h"

UENUM(BlueprintType)
enum class ESprintMode : uint8 {
    Toggle,
    Hold,
    Both,
    HoldInversed,
    LastIndex,
};

