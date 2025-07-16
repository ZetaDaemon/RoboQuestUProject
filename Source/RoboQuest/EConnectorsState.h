#pragma once
#include "CoreMinimal.h"
#include "EConnectorsState.generated.h"

UENUM(BlueprintType)
enum class EConnectorsState : uint8 {
    Entering,
    Exiting,
    Both,
    None,
};

