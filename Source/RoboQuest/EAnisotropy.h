#pragma once
#include "CoreMinimal.h"
#include "EAnisotropy.generated.h"

UENUM(BlueprintType)
enum class EAnisotropy : uint8 {
    Off,
    x2,
    x4,
    x8,
    LastIndex,
};

