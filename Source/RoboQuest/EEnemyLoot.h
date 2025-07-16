#pragma once
#include "CoreMinimal.h"
#include "EEnemyLoot.generated.h"

UENUM(BlueprintType)
enum class EEnemyLoot : uint8 {
    Ticket,
    Wrench,
    LastIndex,
};

