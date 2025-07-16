#pragma once
#include "CoreMinimal.h"
#include "ECollectableType.generated.h"

UENUM(BlueprintType)
enum class ECollectableType : uint8 {
    Key,
    QuestItem,
    LastIndex,
};

