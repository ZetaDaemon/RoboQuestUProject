#pragma once
#include "CoreMinimal.h"
#include "EEnemyLoadingType.generated.h"

UENUM(BlueprintType)
enum class EEnemyLoadingType : uint8 {
    Regular,
    RegularMultiplayer,
    Specific,
    SpecificMultiplayer,
    EliteReplacement,
    NewGamePlusBase,
    NewGamePlusReplacement,
    Indie,
    IndieMultiplayer,
    Arena,
    ArenaMultiplayer,
    Reinforcement,
    ReinforcementMultiplayer,
    RegularWorker,
    LoopingWorker,
    WallTurret,
    Big,
    MainPathPostSASBase,
    MainPathPostSASReplacement,
    SidePath1PostSASBase,
    SidePath1PostSASReplacement,
    SidePath2PostSASBase,
    SidePath2PostSASReplacement,
    MoonBoss,
    InfiniteBoss,
    InfiniteAdditionalEnemies,
    InfiniteAdditionalEnemiesPercent,
};

