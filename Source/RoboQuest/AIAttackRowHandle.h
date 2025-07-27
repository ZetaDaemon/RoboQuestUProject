#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AIAttackRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FAIAttackRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FAIAttackRowHandle();
};

