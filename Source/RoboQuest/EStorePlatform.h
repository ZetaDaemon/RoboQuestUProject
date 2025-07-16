#pragma once
#include "CoreMinimal.h"
#include "EStorePlatform.generated.h"

UENUM(BlueprintType)
enum class EStorePlatform : uint8 {
    Steam,
    MicrosoftStore,
    EGS,
    GOG,
    PlaystationStore,
    MAX,
};

