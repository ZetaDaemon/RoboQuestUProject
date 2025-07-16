#pragma once
#include "CoreMinimal.h"
#include "EMapLocatorType.generated.h"

UENUM(BlueprintType)
enum class EMapLocatorType : uint8 {
    LocalPlayer,
    RemotePlayer,
    Other,
    LastIndex,
};

