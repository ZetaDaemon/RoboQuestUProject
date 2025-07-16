#pragma once
#include "CoreMinimal.h"
#include "EDialogueEvent.generated.h"

UENUM(BlueprintType)
enum class EDialogueEvent : uint8 {
    Start,
    Story,
    Discovery,
    Retry,
    Meta,
    Boss,
    Respawn,
    LastIndex,
};

