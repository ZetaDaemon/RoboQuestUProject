#pragma once
#include "CoreMinimal.h"
#include "EEnemyBoardSelection.generated.h"

UENUM(BlueprintType)
enum class EEnemyBoardSelection : uint8 {
    Random,
    Ordered,
};

