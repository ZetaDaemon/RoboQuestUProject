#pragma once
#include "CoreMinimal.h"
#include "EItemType.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8 {
    Perk,
    PerkUpgrade,
    ClassUpgrade,
    CommonUpgrade,
    Utility,
    InfiniteUpgrade,
};

