#pragma once
#include "CoreMinimal.h"
#include "EJumpadLocation.generated.h"

UENUM(BlueprintType)
enum class EJumpadLocation : uint8 {
    Both,
    Entering,
    Exiting,
    Arena,
};

