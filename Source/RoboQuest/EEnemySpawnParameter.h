#pragma once
#include "CoreMinimal.h"
#include "EEnemySpawnParameter.generated.h"

UENUM(BlueprintType)
enum EEnemySpawnParameter {
    CanLoot,
    AlwaysShielded,
    Elite,
    IsBoss,
    IsBig,
    NoXP,
    HeadbonkBubble,
    EyeProtection,
    TurretEmpower,
    ExplodeOnDeath,
};

