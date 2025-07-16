#pragma once
#include "CoreMinimal.h"
#include "EAOEType.generated.h"

UENUM(BlueprintType)
enum class EAOEType : uint8 {
    Box,
    Sphere,
    Cone,
    Melee,
    LastIndex,
};

