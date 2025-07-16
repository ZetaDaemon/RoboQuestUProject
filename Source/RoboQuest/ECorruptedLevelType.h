#pragma once
#include "CoreMinimal.h"
#include "ECorruptedLevelType.generated.h"

UENUM(BlueprintType)
enum class ECorruptedLevelType : uint8 {
    None,
    Race,
    RaceWithSpeedPickups,
    RaceWithTimePickups,
    Arena,
    Boss,
    MAX,
};

