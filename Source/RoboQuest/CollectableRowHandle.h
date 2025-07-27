#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CollectableRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FCollectableRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FCollectableRowHandle();
};

