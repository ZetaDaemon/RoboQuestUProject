#pragma once
#include "CoreMinimal.h"
#include "ERandomMeshTag.generated.h"

UENUM(BlueprintType)
enum class ERandomMeshTag : uint8 {
    Canyon,
    Mine,
    Oasis,
    Road,
    City,
    CorruptedCity,
    LastIndex,
};

