#pragma once
#include "CoreMinimal.h"
#include "EEnemyBoardPosition.generated.h"

UENUM(BlueprintType)
enum class EEnemyBoardPosition : uint8 {
    All,
    Front,
    Mid,
    Back,
};

