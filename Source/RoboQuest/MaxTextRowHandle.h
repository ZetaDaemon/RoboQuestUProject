#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MaxTextRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FMaxTextRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FMaxTextRowHandle();
};

