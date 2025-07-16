#pragma once
#include "CoreMinimal.h"
#include "EMetaRewardLootType.generated.h"

UENUM(BlueprintType)
enum class EMetaRewardLootType : uint8 {
    FirstStart,
    ActStart,
    AllStart,
    Basecamp,
    LastIndex,
};

