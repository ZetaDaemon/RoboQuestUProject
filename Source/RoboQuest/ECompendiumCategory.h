#pragma once
#include "CoreMinimal.h"
#include "ECompendiumCategory.generated.h"

UENUM(BlueprintType)
enum class ECompendiumCategory : uint8 {
    Weapons,
    Enemies,
    Items,
    Perks,
    Cinematics,
    Gadgets,
    Levels,
    Recap,
    Story,
    MAX,
};

