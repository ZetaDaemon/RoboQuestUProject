#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InfiniteBossRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FInfiniteBossRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FInfiniteBossRowHandle();
};

