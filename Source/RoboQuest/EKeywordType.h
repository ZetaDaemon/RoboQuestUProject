#pragma once
#include "CoreMinimal.h"
#include "EKeywordType.generated.h"

UENUM(BlueprintType)
enum class EKeywordType : uint8 {
    Coloured,
    ColouredCustom,
    Bold,
    Normal,
};

