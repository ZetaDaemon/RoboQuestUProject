#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "LevelGeneratorMutatorRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FLevelGeneratorMutatorRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FLevelGeneratorMutatorRowHandle();
};

