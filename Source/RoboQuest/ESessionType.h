#pragma once
#include "CoreMinimal.h"
#include "ESessionType.generated.h"

UENUM(BlueprintType)
enum class ESessionType : uint8 {
    Private,
    Public,
};

