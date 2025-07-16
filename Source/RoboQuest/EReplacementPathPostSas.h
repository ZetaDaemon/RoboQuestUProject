#pragma once
#include "CoreMinimal.h"
#include "EReplacementPathPostSas.generated.h"

UENUM(BlueprintType)
enum class EReplacementPathPostSas : uint8 {
    MainPath,
    FirstSidePath,
    SecondSidePath,
    MAX,
};

