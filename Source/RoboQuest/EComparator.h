#pragma once
#include "CoreMinimal.h"
#include "EComparator.generated.h"

UENUM(BlueprintType)
enum class EComparator : uint8 {
    Equal,
    Greater,
    Lesser,
};

