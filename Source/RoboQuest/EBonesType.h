#pragma once
#include "CoreMinimal.h"
#include "EBonesType.generated.h"

UENUM(BlueprintType)
enum class EBonesType : uint8 {
    None,
    Destructible,
    Invulnerable,
    Critical,
};

