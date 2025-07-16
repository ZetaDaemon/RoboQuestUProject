#pragma once
#include "CoreMinimal.h"
#include "ENetworkMode.generated.h"

UENUM(BlueprintType)
enum class ENetworkMode : uint8 {
    Solo,
    Multi,
};

