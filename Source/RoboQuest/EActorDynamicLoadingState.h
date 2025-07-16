#pragma once
#include "CoreMinimal.h"
#include "EActorDynamicLoadingState.generated.h"

UENUM(BlueprintType)
enum class EActorDynamicLoadingState : uint8 {
    Near,
    Far,
    Off,
};

