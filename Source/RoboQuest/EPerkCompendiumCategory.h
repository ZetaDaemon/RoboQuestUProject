#pragma once
#include "CoreMinimal.h"
#include "EPerkCompendiumCategory.generated.h"

UENUM(BlueprintType)
enum class EPerkCompendiumCategory : uint8 {
    Common,
    Guardian,
    Engineer,
    Recon,
    Commando,
    Sentinel,
    Magus,
    Superbot,
};

