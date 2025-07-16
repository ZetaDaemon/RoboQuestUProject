#pragma once
#include "CoreMinimal.h"
#include "EWeaponMetaRewardModifier.generated.h"

UENUM(BlueprintType)
enum class EWeaponMetaRewardModifier : uint8 {
    None,
    Base,
    Merchant,
    Special,
    Max,
    Starter,
};

