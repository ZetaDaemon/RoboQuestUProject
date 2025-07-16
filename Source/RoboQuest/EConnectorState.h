#pragma once
#include "CoreMinimal.h"
#include "EConnectorState.generated.h"

UENUM(BlueprintType)
enum class EConnectorState : uint8 {
    Close,
    Lock,
    Open,
};

