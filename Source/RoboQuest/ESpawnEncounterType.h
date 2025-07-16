#pragma once
#include "CoreMinimal.h"
#include "ESpawnEncounterType.generated.h"

UENUM(BlueprintType)
enum class ESpawnEncounterType : uint8 {
    Connector,
    Tile,
    Indie,
};

