#pragma once
#include "CoreMinimal.h"
#include "EStat.generated.h"

UENUM(BlueprintType)
enum class EStat : uint8 {
    Health,
    MoveSpeedRatio,
    DamageTakenRatio,
    Damage,
    Firerate,
    Cooldown,
    Duration,
    BaseSpread,
    RecoilPerShootPitch,
    HitAmount,
    SpreadPerShot,
    SpreadRecover,
    AmmoInClip,
    AmmoTotal,
    ReloadTime,
    ImpactForce,
    ImpactResistance,
    StunResistance,
    MaxTargets,
    WeaponSlot,
    Shield,
    CriticalModifier,
    FalloffDistance,
    AreaScaleRatio,
    FriendlyDamage,
    CoolingDamageRatio,
    Experience,
    Speed,
    Energy,
    IceResistance,
    AutoCriticalLuck,
    CoolingSpeedRatio,
    LastIndex,
};

