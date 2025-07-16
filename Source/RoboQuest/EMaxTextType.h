#pragma once
#include "CoreMinimal.h"
#include "EMaxTextType.generated.h"

UENUM(BlueprintType)
enum class EMaxTextType : uint8 {
    Busy,
    Chill,
    Ready,
    Danger,
    MAX,
};

