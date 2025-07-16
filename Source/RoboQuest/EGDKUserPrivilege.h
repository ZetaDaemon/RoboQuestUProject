#pragma once
#include "CoreMinimal.h"
#include "EGDKUserPrivilege.generated.h"

UENUM(BlueprintType)
enum class EGDKUserPrivilege : uint8 {
    None,
    CrossPlay = 185,
    Clubs = 188,
    Sessions,
    Broadcast,
    ManageProfilePrivacy = 196,
    GameDvr = 198,
    MultiplayerParties = 203,
    CloudManageSession = 207,
    CloudJoinSession,
    CloudSavedGames,
    SocialNetworkSharing = 220,
    UserGeneratedContent = 247,
    Communications = 252,
    Multiplayer = 254,
    AddFriends,
};

