#pragma once
#include "CoreMinimal.h"
#include "EAreaDecalMaterialTypes.generated.h"

UENUM(BlueprintType)
enum class EAreaDecalMaterialTypes : uint8 {
    Small,
    Medium,
    Big,
    Tileable,
    GroundMarkMortar,
    NoDecal,
    MAX,
};

