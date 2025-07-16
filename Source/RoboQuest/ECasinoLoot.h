#pragma once
#include "CoreMinimal.h"
#include "ECasinoLoot.generated.h"

UENUM(BlueprintType)
enum class ECasinoLoot : uint8 {
    Weapon,
    Health,
    Wrench,
    Ticket,
    Nothing,
    LastIndex,
};

