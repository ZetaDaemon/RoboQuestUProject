#pragma once
#include "CoreMinimal.h"
#include "EProjectileType.generated.h"

UENUM(BlueprintType)
enum class EProjectileType : uint8 {
    Player,
    Ally,
    AI,
};

