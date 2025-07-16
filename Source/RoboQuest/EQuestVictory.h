#pragma once
#include "CoreMinimal.h"
#include "EQuestVictory.generated.h"

UENUM(BlueprintType)
enum class EQuestVictory : uint8 {
    TriggerBox,
    Collectables,
    KillAllEnemies,
};

