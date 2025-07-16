#pragma once
#include "CoreMinimal.h"
#include "EMaxTextLocation.generated.h"

UENUM(BlueprintType)
enum class EMaxTextLocation : uint8 {
    Start,
    SAS,
    Boss,
    MAX,
};

