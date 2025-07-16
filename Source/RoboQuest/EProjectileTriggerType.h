#pragma once
#include "CoreMinimal.h"
#include "EProjectileTriggerType.generated.h"

UENUM(BlueprintType)
enum class EProjectileTriggerType : uint8 {
    Time,
    Range,
    LastIndex,
};

