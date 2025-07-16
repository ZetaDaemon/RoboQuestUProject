#pragma once
#include "CoreMinimal.h"
#include "EEncounterSize.generated.h"

UENUM(BlueprintType)
enum class EEncounterSize : uint8 {
    Half,
    Full,
    LastIndex,
};

