#pragma once
#include "CoreMinimal.h"
#include "EAspectRatio.generated.h"

UENUM(BlueprintType)
enum class EAspectRatio : uint8 {
    r4x3,
    r16x9,
    r16x10,
    r21x9,
    r32x9,
    LastIndex,
};

