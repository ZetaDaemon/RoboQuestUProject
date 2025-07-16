#pragma once
#include "CoreMinimal.h"
#include "EArenaSpawnerType.generated.h"

UENUM(BlueprintType)
enum class EArenaSpawnerType : uint8 {
    Ground,
    Flying,
    LastIndex,
};

