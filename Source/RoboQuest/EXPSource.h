#pragma once
#include "CoreMinimal.h"
#include "EXPSource.generated.h"

UENUM(BlueprintType)
enum class EXPSource : uint8 {
    Enemy,
    Boss,
    Other,
    LastIndex,
};

