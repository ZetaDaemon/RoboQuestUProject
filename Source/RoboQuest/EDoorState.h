#pragma once
#include "CoreMinimal.h"
#include "EDoorState.generated.h"

UENUM(BlueprintType)
enum class EDoorState : uint8 {
    Opened,
    Closed,
    LockOpened,
    LockClosed,
    LockedBySecret,
    LastIndex,
};

