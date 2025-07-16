#pragma once
#include "CoreMinimal.h"
#include "ECorruptedRaceDifficulty.generated.h"

UENUM(BlueprintType)
enum class ECorruptedRaceDifficulty : uint8 {
    Discovery,
    Easy,
    Others,
    MAX,
};

