#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "Engine/DataTable.h"
#include "OnomatopoeiaRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FOnomatopoeiaRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FOnomatopoeiaRowHandle();
};

