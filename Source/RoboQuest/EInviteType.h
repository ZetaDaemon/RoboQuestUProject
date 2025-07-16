#pragma once
#include "CoreMinimal.h"
#include "EInviteType.generated.h"

UENUM(BlueprintType)
enum class EInviteType : uint8 {
    Inbound,
    Outbound,
};

