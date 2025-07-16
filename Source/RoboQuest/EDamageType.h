#pragma once
#include "CoreMinimal.h"
#include "EDamageType.generated.h"

UENUM(BlueprintType)
enum class EDamageType : uint8 {
    Bullet,
    Explosion,
    Laser,
    Physic,
    Burn,
    Shock,
    Ice,
    Mark,
    HeavyBullet,
    HeavyLaser,
    LastIndex,
};

