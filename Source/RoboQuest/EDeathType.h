#pragma once
#include "CoreMinimal.h"
#include "EDeathType.generated.h"

UENUM(BlueprintType)
enum class EDeathType : uint8 {
    None,
    Enemy,
    ChallengeRoom,
    Boss,
};

