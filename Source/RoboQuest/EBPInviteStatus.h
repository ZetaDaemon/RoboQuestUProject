#pragma once
#include "CoreMinimal.h"
#include "EBPInviteStatus.generated.h"

UENUM(BlueprintType)
enum class EBPInviteStatus : uint8 {
    Unknown,
    Accepted,
    PendingInbound,
    PendingOutbound,
    Blocked,
    Suggested,
};

