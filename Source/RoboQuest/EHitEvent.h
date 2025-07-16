#pragma once
#include "CoreMinimal.h"
#include "EHitEvent.generated.h"

UENUM(BlueprintType)
enum class EHitEvent : uint8 {
    Hit,
    Death,
};

