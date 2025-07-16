#pragma once
#include "CoreMinimal.h"
#include "ESuperBotGadgetLockedState.generated.h"

UENUM(BlueprintType)
enum class ESuperBotGadgetLockedState : uint8 {
    None,
    Equipped,
    Unequipped,
};

