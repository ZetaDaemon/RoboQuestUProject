#pragma once
#include "CoreMinimal.h"
#include "EAssetLoading.generated.h"

UENUM(BlueprintType)
enum class EAssetLoading : uint8 {
    Tiles,
    InteriorSpecial,
    Bosses,
    BossLayers,
    BossSequences,
    Enemies,
    Roofs,
    Borders,
    EndLevelBeam,
    ReplacementMeshes,
    HoleSpawners,
    InteriorInfiniteBoss,
    LastIndex,
};

