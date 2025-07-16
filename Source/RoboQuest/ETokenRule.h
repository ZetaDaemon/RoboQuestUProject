#pragma once
#include "CoreMinimal.h"
#include "ETokenRule.generated.h"

UENUM(BlueprintType)
enum class ETokenRule : uint8 {
    None,
    Simple,
    Priority,
};

