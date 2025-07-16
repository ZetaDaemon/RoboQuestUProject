#pragma once
#include "CoreMinimal.h"
#include "EBubbleSpawnAnimation.generated.h"

UENUM(BlueprintType)
enum class EBubbleSpawnAnimation : uint8 {
    NoAnimation,
    Pop,
    Fade,
    MAX,
};

