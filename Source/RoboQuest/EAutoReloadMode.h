#pragma once
#include "CoreMinimal.h"
#include "EAutoReloadMode.generated.h"

UENUM(BlueprintType)
enum class EAutoReloadMode : uint8 {
    Always,
    Once,
    Never,
    LastIndex,
};

