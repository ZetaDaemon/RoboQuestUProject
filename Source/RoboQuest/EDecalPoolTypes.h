#pragma once
#include "CoreMinimal.h"
#include "EDecalPoolTypes.generated.h"

UENUM(BlueprintType)
enum class EDecalPoolTypes : uint8 {
    Impact,
    Area,
    EnemyDeath,
    MAX,
};

