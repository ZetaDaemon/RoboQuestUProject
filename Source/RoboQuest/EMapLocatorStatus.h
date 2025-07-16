#pragma once
#include "CoreMinimal.h"
#include "EMapLocatorStatus.generated.h"

UENUM(BlueprintType)
enum class EMapLocatorStatus : uint8 {
    Both,
    MapOnly,
    MiniMapOnly,
};

