#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "LootRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FLootRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FLootRowHandle();
};
FORCEINLINE uint32 GetTypeHash(const FLootRowHandle) { return 0; }

