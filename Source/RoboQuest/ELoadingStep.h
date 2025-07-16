#pragma once
#include "CoreMinimal.h"
#include "ELoadingStep.generated.h"

UENUM(BlueprintType)
enum class ELoadingStep : uint8 {
    Connecting,
    GeneratingLevel,
    GeneratingEnemies,
    GeneratingNavigation,
    Initialization,
    LoadingAssets,
    UnloadingLevel,
    WaitingOtherPlayer,
    GeneratingLoot,
    PlayerSaveInitialization,
};

