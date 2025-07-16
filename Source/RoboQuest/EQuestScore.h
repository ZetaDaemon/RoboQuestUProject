#pragma once
#include "CoreMinimal.h"
#include "EQuestScore.generated.h"

UENUM(BlueprintType)
enum class EQuestScore : uint8 {
    CellsAndTime,
    TimeOnly,
};

