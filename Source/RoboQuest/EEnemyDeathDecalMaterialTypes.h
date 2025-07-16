#pragma once
#include "CoreMinimal.h"
#include "EEnemyDeathDecalMaterialTypes.generated.h"

UENUM(BlueprintType)
enum class EEnemyDeathDecalMaterialTypes : uint8 {
    Small,
    Medium,
    Big,
    Crater,
    Goliath,
    Ice,
    Burn,
    NoDecal,
    MAX,
};

