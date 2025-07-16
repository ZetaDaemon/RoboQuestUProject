#pragma once
#include "CoreMinimal.h"
#include "EHoleSpawnerType.generated.h"

UENUM(BlueprintType)
enum class EHoleSpawnerType : uint8 {
    Opened,
    Closed,
    Boss,
};

