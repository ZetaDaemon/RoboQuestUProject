#pragma once
#include "CoreMinimal.h"
#include "EPickup.generated.h"

UENUM(BlueprintType)
enum class EPickup : uint8 {
    Experience,
    Health,
    Elite,
    Wrench,
    Shield,
    Scrap,
    Ticket,
    MaxHealth,
    Speed,
    Time,
    Corrupted,
    LastIndex,
};

