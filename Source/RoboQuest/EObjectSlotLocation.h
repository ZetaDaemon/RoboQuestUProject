#pragma once
#include "CoreMinimal.h"
#include "EObjectSlotLocation.generated.h"

UENUM(BlueprintType)
enum class EObjectSlotLocation : uint8 {
    Tile,
    Enter,
    ExitToMainPath,
    ExitToSidePath,
    LastIndex,
};

