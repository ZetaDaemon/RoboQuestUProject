#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "Engine/DataTable.h"
#include "LevelRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FLevelRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FLevelRowHandle();
};
FORCEINLINE uint32 GetTypeHash(const FLevelRowHandle) { return 0; }

