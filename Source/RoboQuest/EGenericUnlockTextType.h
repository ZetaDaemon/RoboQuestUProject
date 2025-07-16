#pragma once
#include "CoreMinimal.h"
#include "EGenericUnlockTextType.generated.h"

UENUM(BlueprintType)
enum class EGenericUnlockTextType : uint8 {
    None,
    Quest,
    Path,
    Secret,
    Area,
    UnlockSound,
    LastIndex,
};

