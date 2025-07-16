#pragma once
#include "CoreMinimal.h"
#include "EDamageTypeGameplay.generated.h"

UENUM(BlueprintType)
enum class EDamageTypeGameplay : uint8 {
    Bullet,
    Laser,
    Explosive,
    Ice,
    Burn,
    Shock,
    Special,
    Melee,
    LastIndex,
};

