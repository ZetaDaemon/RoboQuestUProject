#pragma once
#include "CoreMinimal.h"
#include "EUnlockLayout.generated.h"

UENUM(BlueprintType)
enum class EUnlockLayout : uint8 {
    Gadget,
    Class,
    Crystal,
    Story,
    Difficulty,
    Collectable,
    Mutator,
    Generic,
    LastIndex,
};

