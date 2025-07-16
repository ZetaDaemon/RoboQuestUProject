#pragma once
#include "CoreMinimal.h"
#include "EAITag.generated.h"

UENUM(BlueprintType)
enum class EAITag : uint8 {
    Short,
    Middle,
    Long,
    Turret,
    Big,
    Support,
    MiniBoss,
    LastIndex,
};

