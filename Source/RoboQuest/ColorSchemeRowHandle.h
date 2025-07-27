#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ColorSchemeRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FColorSchemeRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FColorSchemeRowHandle();
};

