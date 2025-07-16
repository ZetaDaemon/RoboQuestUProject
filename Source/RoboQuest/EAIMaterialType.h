#pragma once
#include "CoreMinimal.h"
#include "EAIMaterialType.generated.h"

UENUM(BlueprintType)
enum class EAIMaterialType : uint8 {
    Base,
    Iteration,
    Eye,
    Cable,
};

