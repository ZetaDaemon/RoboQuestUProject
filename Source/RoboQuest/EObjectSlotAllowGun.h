#pragma once
#include "CoreMinimal.h"
#include "EObjectSlotAllowGun.generated.h"

UENUM(BlueprintType)
enum class EObjectSlotAllowGun : uint8 {
    AllowGun,
    NoGun,
    OnlyGun,
};

