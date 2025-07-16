#pragma once
#include "CoreMinimal.h"
#include "EBPReportPlayerReason.generated.h"

UENUM(BlueprintType)
enum class EBPReportPlayerReason : uint8 {
    Invalid,
    Cheating,
    Exploiting,
    OffensiveProfile,
    VerbalAbuse,
    Scamming,
    Spamming,
    Other,
};

