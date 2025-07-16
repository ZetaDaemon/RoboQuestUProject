#pragma once
#include "CoreMinimal.h"
#include "EStoryLocation.generated.h"

UENUM(BlueprintType)
enum class EStoryLocation : uint8 {
    Anywhere,
    PreSas,
    PostSasMainPath,
    PostSasFirstSidePath,
    PostSasSecondSidePath,
    PostSasEveryPath,
    Custom,
    MAX,
};

