#pragma once
#include "CoreMinimal.h"
#include "ETraceType.generated.h"

UENUM(BlueprintType)
enum class ETraceType : uint8 {
    Raycast,
    Projectile,
    Box,
    Sphere,
    Cone,
};

