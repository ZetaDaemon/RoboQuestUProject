#pragma once
#include "CoreMinimal.h"
#include "EEndScreenType.generated.h"

UENUM(BlueprintType)
enum class EEndScreenType : uint8 {
    EndLevel,
    Victory,
    GameOver,
    MAX,
};

