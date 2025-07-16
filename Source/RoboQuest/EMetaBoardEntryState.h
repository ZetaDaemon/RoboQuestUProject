#pragma once
#include "CoreMinimal.h"
#include "EMetaBoardEntryState.generated.h"

UENUM(BlueprintType)
enum class EMetaBoardEntryState : uint8 {
    Locked,
    Unpurchased,
    InProgress,
    Purchased,
};

