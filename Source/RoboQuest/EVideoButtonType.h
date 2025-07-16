#pragma once
#include "CoreMinimal.h"
#include "EVideoButtonType.generated.h"

UENUM(BlueprintType)
enum class EVideoButtonType : uint8 {
    Play,
    Pause,
    Next,
    Previous,
    MAX,
};

