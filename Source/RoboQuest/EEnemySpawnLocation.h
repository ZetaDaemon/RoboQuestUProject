#pragma once
#include "CoreMinimal.h"
#include "EEnemySpawnLocation.generated.h"

UENUM(BlueprintType)
enum class EEnemySpawnLocation : uint8 {
    Connector,
    Tile,
    Both,
};

