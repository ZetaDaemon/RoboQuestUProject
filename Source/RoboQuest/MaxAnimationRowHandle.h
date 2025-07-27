#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MaxAnimationRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FMaxAnimationRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FMaxAnimationRowHandle();
};

