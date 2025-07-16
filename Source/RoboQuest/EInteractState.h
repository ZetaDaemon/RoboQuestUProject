#pragma once
#include "CoreMinimal.h"
#include "EInteractState.generated.h"

UENUM(BlueprintType)
enum class EInteractState : uint8 {
    Hide,
    Deactivate,
    Nothing,
};

