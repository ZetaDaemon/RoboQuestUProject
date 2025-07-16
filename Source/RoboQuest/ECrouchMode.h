#pragma once
#include "CoreMinimal.h"
#include "ECrouchMode.generated.h"

UENUM(BlueprintType)
enum class ECrouchMode : uint8 {
    Toggle,
    Hold,
    Both,
    LastIndex,
};

