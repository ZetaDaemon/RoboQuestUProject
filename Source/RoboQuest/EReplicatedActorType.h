#pragma once
#include "CoreMinimal.h"
#include "EReplicatedActorType.generated.h"

UENUM(BlueprintType)
enum class EReplicatedActorType : uint8 {
    Player,
    AI,
    Boss,
    Interactive,
    Ally,
    Door,
    Weapon,
    Big,
    Merchant,
    LastIndex,
};

