#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "ModAnimationRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FModAnimationRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FModAnimationRowHandle();
};

