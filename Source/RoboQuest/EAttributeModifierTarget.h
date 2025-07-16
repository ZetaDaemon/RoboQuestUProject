#pragma once
#include "CoreMinimal.h"
#include "EAttributeModifierTarget.generated.h"

UENUM(BlueprintType)
enum class EAttributeModifierTarget : uint8 {
    Player,
    Bash,
    Skill,
    Weapon,
    Global,
};

