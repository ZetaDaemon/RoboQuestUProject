#pragma once
#include "CoreMinimal.h"
#include "EMultiplayerLoot.generated.h"

UENUM(BlueprintType)
enum class EMultiplayerLoot : uint8 {
    Shared,
    LocalFirstPlayer,
    LocalSecondPlayer,
    LastIndex,
};

