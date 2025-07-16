#pragma once
#include "CoreMinimal.h"
#include "EScopeMode.generated.h"

UENUM(BlueprintType)
enum class EScopeMode : uint8 {
    Hold,
    Toggle,
    LastIndex,
};

