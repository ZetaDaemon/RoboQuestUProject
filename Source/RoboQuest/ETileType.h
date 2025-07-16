#pragma once
#include "CoreMinimal.h"
#include "ETileType.generated.h"

UENUM(BlueprintType)
enum class ETileType : uint8 {
    Arena,
    Corridor,
    Start,
    End,
    Special,
    Boss,
    Sas,
    Story,
    Wall,
    SpecificWall,
    MoonBoss,
    InfiniteBoss,
    LastIndex,
};

