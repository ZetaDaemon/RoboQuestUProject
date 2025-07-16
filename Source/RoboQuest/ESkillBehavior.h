#pragma once
#include "CoreMinimal.h"
#include "ESkillBehavior.generated.h"

UENUM(BlueprintType)
enum class ESkillBehavior : uint8 {
    Fast,
    Slow,
    Spark,
    None,
};

