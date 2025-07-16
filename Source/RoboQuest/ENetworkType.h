#pragma once
#include "CoreMinimal.h"
#include "ENetworkType.generated.h"

UENUM(BlueprintType)
enum class ENetworkType : uint8 {
    Client,
    Server,
    Multicast,
};

