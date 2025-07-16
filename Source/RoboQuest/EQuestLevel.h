#pragma once
#include "CoreMinimal.h"
#include "EQuestLevel.generated.h"

UENUM(BlueprintType)
enum class EQuestLevel : uint8 {
    SnapshotSam,
    Slim,
    PapyPawn,
    LastIndex,
};

