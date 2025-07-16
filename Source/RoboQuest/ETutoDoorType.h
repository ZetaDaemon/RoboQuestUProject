#pragma once
#include "CoreMinimal.h"
#include "ETutoDoorType.generated.h"

UENUM(BlueprintType)
enum class ETutoDoorType : uint8 {
    NotInTuto,
    Start,
    Ability,
    Sas,
    PreSkill,
};

