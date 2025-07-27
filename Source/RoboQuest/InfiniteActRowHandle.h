#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InfiniteActRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FInfiniteActRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FInfiniteActRowHandle();
};

