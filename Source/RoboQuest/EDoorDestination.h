#pragma once
#include "CoreMinimal.h"
#include "EDoorDestination.generated.h"

UENUM(BlueprintType)
enum class EDoorDestination : uint8 {
    MainPath,
    SidePath,
    BossPath,
    SpecialPath,
    Locked,
    LastIndex,
};

