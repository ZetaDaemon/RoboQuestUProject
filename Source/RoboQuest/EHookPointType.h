#pragma once
#include "CoreMinimal.h"
#include "EHookPointType.generated.h"

UENUM(BlueprintType)
enum class EHookPointType : uint8 {
    Act1,
    Act2,
    Act3,
    Corrupted,
    LastIndex,
};

