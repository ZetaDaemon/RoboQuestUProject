#pragma once
#include "CoreMinimal.h"
#include "BlockedPlayer.h"
#include "PlayerBlockList.generated.h"

USTRUCT(BlueprintType)
struct FPlayerBlockList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBlockedPlayer> BlockedEOSPlayers;
    
    ROBOQUEST_API FPlayerBlockList();
};

