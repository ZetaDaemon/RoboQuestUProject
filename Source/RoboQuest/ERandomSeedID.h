#pragma once
#include "CoreMinimal.h"
#include "ERandomSeedID.generated.h"

UENUM(BlueprintType)
enum class ERandomSeedID : uint8 {
    LevelGeneration,
    EnemyGeneration,
    LootGeneration,
    Perk,
    Layout,
    LocalLoot,
    MetaRewards,
    LevelRewards,
    MetaRewardsMulti,
    InfiniteRun,
    LastIndex,
};

