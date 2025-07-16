#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "OnomatopoeiaRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FOnomatopoeiaRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FOnomatopoeiaRowHandle();
};

