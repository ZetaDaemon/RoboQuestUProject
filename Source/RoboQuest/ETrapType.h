#pragma once
#include "CoreMinimal.h"
#include "ETrapType.generated.h"

UENUM(BlueprintType)
enum class ETrapType : uint8 {
    Laser,
    LaserNoEnds,
    Lava,
    Freeze,
    LightingLaser,
    WallTurret,
    Smoke,
    HoleSpawner,
    Projectile,
    ConeTrap,
    Fire,
    LastIndex,
};

