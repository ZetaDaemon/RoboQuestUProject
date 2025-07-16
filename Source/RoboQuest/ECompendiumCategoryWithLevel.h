#pragma once
#include "CoreMinimal.h"
#include "ECompendiumCategoryWithLevel.generated.h"

UENUM(BlueprintType)
enum class ECompendiumCategoryWithLevel : uint8 {
    Weapons,
    Enemies,
    Levels,
    MAX,
};

