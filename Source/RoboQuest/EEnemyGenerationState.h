#pragma once
#include "CoreMinimal.h"
#include "EEnemyGenerationState.generated.h"

UENUM(BlueprintType)
enum class EEnemyGenerationState : uint8 {
    Enabled,
    SpawnOnly,
    VisibleOnly,
    WorkersOnly,
    BossOnly,
    Disabled,
};

