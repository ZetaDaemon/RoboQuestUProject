#pragma once
#include "CoreMinimal.h"
#include "ESquadPointType.generated.h"

UENUM(BlueprintType)
enum class ESquadPointType : uint8 {
    Normal,
    Turret,
    Flying,
    LastIndex,
};

