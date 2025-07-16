#pragma once
#include "CoreMinimal.h"
#include "ESocketLocation.generated.h"

UENUM(BlueprintType)
enum class ESocketLocation : uint8 {
    Head,
    Overhead,
    Body,
    Root,
};

