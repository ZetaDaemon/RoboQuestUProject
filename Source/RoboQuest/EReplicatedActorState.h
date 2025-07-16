#pragma once
#include "CoreMinimal.h"
#include "EReplicatedActorState.generated.h"

UENUM(BlueprintType)
enum class EReplicatedActorState : uint8 {
    PendingInit,
    Init,
    Active,
    Unloaded,
    Destroyed,
    LastIndex,
};

