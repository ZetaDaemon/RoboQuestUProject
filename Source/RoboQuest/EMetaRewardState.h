#pragma once
#include "CoreMinimal.h"
#include "EMetaRewardState.generated.h"

UENUM(BlueprintType)
enum class EMetaRewardState : uint8 {
    Hidden,
    Unpurchasable,
    Purchasable,
    Purchased,
};

