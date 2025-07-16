#pragma once
#include "CoreMinimal.h"
#include "ETextTranslationAnimation.generated.h"

UENUM(BlueprintType)
enum class ETextTranslationAnimation : uint8 {
    SemiAuto,
    Auto,
    Burn,
    Spark,
};

