#pragma once
#include "CoreMinimal.h"
#include "EControllerScheme.generated.h"

UENUM(BlueprintType)
enum class EControllerScheme : uint8 {
    Keyboard,
    Gamepad,
    Mouse,
};

