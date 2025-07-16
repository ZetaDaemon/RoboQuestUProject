#pragma once
#include "CoreMinimal.h"
#include "EDoorBehaviour.generated.h"

UENUM(BlueprintType)
enum class EDoorBehaviour : uint8 {
    Normal,
    StayOpened,
    StayClosed,
    ForceOpen,
    ForceClose,
    ForceOpenThenStayClosed,
    ForceOpenThenNormal,
    LastIndex,
};

