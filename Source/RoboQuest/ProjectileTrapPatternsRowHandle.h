#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ProjectileTrapPatternsRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FProjectileTrapPatternsRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FProjectileTrapPatternsRowHandle();
};

