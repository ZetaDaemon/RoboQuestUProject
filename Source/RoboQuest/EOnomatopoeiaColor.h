#pragma once
#include "CoreMinimal.h"
#include "EOnomatopoeiaColor.generated.h"

UENUM(BlueprintType)
enum class EOnomatopoeiaColor : uint8 {
    Gen1,
    Gen2,
    Gen3,
    Player,
    Neutral,
    Fire,
    Shock,
    Ice,
    Gen1Cooling,
    Gen2Cooling,
    LastIndex,
};

