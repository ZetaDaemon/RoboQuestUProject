#pragma once
#include "CoreMinimal.h"
#include "EAIMovementType.generated.h"

UENUM(BlueprintType)
enum class EAIMovementType : uint8 {
    Static,
    Walking,
    Flying,
};

