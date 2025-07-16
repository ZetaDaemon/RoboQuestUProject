#pragma once
#include "CoreMinimal.h"
#include "ESkillType.generated.h"

UENUM(BlueprintType)
enum class ESkillType : uint8 {
    Weapon,
    Player,
    AI,
};

