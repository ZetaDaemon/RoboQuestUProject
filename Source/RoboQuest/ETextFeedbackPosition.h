#pragma once
#include "CoreMinimal.h"
#include "ETextFeedbackPosition.generated.h"

UENUM(BlueprintType)
enum class ETextFeedbackPosition : uint8 {
    Alternate,
    Random,
    Left,
    Right,
};

