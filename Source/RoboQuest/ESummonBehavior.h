#pragma once
#include "CoreMinimal.h"
#include "ESummonBehavior.generated.h"

UENUM(BlueprintType)
enum class ESummonBehavior : uint8 {
    Released,
    Pressed,
    Toggle,
};

