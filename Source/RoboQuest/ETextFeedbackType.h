#pragma once
#include "CoreMinimal.h"
#include "ETextFeedbackType.generated.h"

UENUM(BlueprintType)
enum class ETextFeedbackType : uint8 {
    Health,
    Damage,
    PowerCell,
    Experience,
    MAX,
};

