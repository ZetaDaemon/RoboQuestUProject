#pragma once
#include "CoreMinimal.h"
#include "ESpecificLayout.generated.h"

UENUM(BlueprintType)
enum class ESpecificLayout : uint8 {
    None,
    FourTiles,
    FourTilesWithWalls,
    SixTilesWithWalls,
    OneTileWithWalls,
};

