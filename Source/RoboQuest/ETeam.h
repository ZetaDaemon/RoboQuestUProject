#pragma once
#include "CoreMinimal.h"
#include "ETeam.generated.h"

UENUM(BlueprintType)
enum class ETeam : uint8 {
    Player,
    Ally,
    Enemy,
    Environment,
    Myself,
    Dummy,
    LastIndex,
};

