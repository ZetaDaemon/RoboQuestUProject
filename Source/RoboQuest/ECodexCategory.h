#pragma once
#include "CoreMinimal.h"
#include "ECodexCategory.generated.h"

UENUM(BlueprintType)
enum class ECodexCategory : uint8 {
    All,
    Weapons,
    Loadouts,
    Perks,
    Artefacts,
    Enemies,
    Levels,
    LastIndex,
};

