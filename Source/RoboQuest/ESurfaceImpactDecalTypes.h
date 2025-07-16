#pragma once
#include "CoreMinimal.h"
#include "ESurfaceImpactDecalTypes.generated.h"

UENUM(BlueprintType)
enum class ESurfaceImpactDecalTypes : uint8 {
    Crack,
    NoCrack,
    NoDecal,
    MAX,
};

