#pragma once
#include "CoreMinimal.h"
#include "ETilesDynamicLoadingState.generated.h"

UENUM(BlueprintType)
enum class ETilesDynamicLoadingState : uint8 {
    CurrentAndAdjacentTiles,
    CurrentTileOnly,
    AllTilesLoaded,
};

