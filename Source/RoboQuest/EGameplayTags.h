#pragma once
#include "CoreMinimal.h"
#include "EGameplayTags.generated.h"

UENUM(BlueprintType)
enum class EGameplayTags : uint8 {
    Explosive,
    Cooling,
    Burn,
    Shock,
    Ice,
    Swift,
    Bullet,
    Laser,
    Special,
    Secondary,
    Heavy,
    Summon,
    Magazine,
    Melee,
    Bash,
    Critical,
    LastIndex,
};

