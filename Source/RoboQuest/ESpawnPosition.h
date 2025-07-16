#pragma once
#include "CoreMinimal.h"
#include "ESpawnPosition.generated.h"

UENUM(BlueprintType)
enum class ESpawnPosition : uint8 {
    Around,
    InFront,
    Behind,
    Target,
};

