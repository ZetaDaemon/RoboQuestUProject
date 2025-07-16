#pragma once
#include "CoreMinimal.h"
#include "EBPPresenceInfo.generated.h"

UENUM(BlueprintType)
enum class EBPPresenceInfo : uint8 {
    Offline,
    Online,
    PlayingOtherGame,
    PlayingThisGame,
};

