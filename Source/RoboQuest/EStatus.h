#pragma once
#include "CoreMinimal.h"
#include "EStatus.generated.h"

UENUM(BlueprintType)
enum class EStatus : uint8 {
    Energized,
    Stealth,
    Slowed,
    Shielded,
    Scopped,
    Marked,
    Burn,
    Stun,
    Electrified,
    Berzerk,
    Empower,
    Leashed,
    Frozen,
    Shocked,
    Confused,
    Staggered,
    Blind,
    Speed,
    Focused,
    LastIndex,
};

