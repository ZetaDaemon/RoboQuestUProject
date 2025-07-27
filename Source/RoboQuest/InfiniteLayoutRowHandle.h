#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InfiniteLayoutRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FInfiniteLayoutRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FInfiniteLayoutRowHandle();
};

