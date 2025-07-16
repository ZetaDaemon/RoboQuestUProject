#pragma once
#include "CoreMinimal.h"
#include "ESquadPointTag.generated.h"

UENUM(BlueprintType)
enum class ESquadPointTag : uint8 {
    Front,
    Mid,
    Back,
    LastIndex,
};

