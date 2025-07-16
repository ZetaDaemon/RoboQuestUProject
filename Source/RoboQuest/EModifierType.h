#pragma once
#include "CoreMinimal.h"
#include "EModifierType.generated.h"

UENUM(BlueprintType)
enum class EModifierType : uint8 {
    Stat,
    StateMachine,
    LastIndex,
};

