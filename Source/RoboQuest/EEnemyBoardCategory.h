#pragma once
#include "CoreMinimal.h"
#include "EEnemyBoardCategory.generated.h"

UENUM(BlueprintType)
enum class EEnemyBoardCategory : uint8 {
    Regular,
    Specific,
    Indie,
    Arena,
    LastIndex,
};

