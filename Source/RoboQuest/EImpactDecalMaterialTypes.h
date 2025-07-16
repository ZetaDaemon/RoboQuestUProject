#pragma once
#include "CoreMinimal.h"
#include "EImpactDecalMaterialTypes.generated.h"

UENUM(BlueprintType)
enum class EImpactDecalMaterialTypes : uint8 {
    Gen1Crack,
    Gen1NoCrack,
    Gen2Crack,
    Gen2NoCrack,
    MAX,
};

