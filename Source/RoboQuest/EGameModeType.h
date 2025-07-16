#pragma once
#include "CoreMinimal.h"
#include "EGameModeType.generated.h"

UENUM(BlueprintType)
enum class EGameModeType : uint8 {
    Default,
    Generator,
    Menu,
};

