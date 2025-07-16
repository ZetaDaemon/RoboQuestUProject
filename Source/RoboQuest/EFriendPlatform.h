#pragma once
#include "CoreMinimal.h"
#include "EFriendPlatform.generated.h"

UENUM(BlueprintType)
enum class EFriendPlatform : uint8 {
    Unknown,
    Steam,
    EpicGames,
    Xbox,
    PlayStation,
    Switch,
    GOG,
};

