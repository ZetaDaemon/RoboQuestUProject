#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MetaRewardStructureRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FMetaRewardStructureRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FMetaRewardStructureRowHandle();
};

