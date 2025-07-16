#pragma once
#include "CoreMinimal.h"
#include "EItemPointType.generated.h"

UENUM(BlueprintType)
enum class EItemPointType : uint8 {
    Class,
    Upgrade,
    Infinite,
    LastIndex,
};

