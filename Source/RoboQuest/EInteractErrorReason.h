#pragma once
#include "CoreMinimal.h"
#include "EInteractErrorReason.generated.h"

UENUM(BlueprintType)
enum class EInteractErrorReason : uint8 {
    Custom,
    Wrench,
    Ticket,
    WeaponTicket,
    CrystalPowder,
    LastIndex,
};

