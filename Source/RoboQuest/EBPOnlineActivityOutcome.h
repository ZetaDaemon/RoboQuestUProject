#pragma once
#include "CoreMinimal.h"
#include "EBPOnlineActivityOutcome.generated.h"

UENUM(BlueprintType)
enum class EBPOnlineActivityOutcome : uint8 {
    Completed,
    Failed,
    Cancelled,
};

