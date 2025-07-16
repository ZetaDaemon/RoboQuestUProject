#pragma once
#include "CoreMinimal.h"
#include "EInputRecordType.generated.h"

UENUM(BlueprintType)
enum class EInputRecordType : uint8 {
    None,
    Record,
    RecordIfPressed,
    Both,
    Skill,
};

