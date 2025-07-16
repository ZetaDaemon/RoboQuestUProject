#pragma once
#include "CoreMinimal.h"
#include "EEncounterType.generated.h"

UENUM(BlueprintType)
enum class EEncounterType : uint8 {
    Connector,
    Tile,
    LastIndex,
};

