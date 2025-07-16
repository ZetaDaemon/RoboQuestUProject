#pragma once
#include "CoreMinimal.h"
#include "EBPFileReadStorageType.generated.h"

UENUM(BlueprintType)
enum class EBPFileReadStorageType : uint8 {
    Player,
    Title,
};

