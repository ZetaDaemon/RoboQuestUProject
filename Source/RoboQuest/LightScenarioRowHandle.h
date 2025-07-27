#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataTableRowHandle -FallbackName=DataTableRowHandle
#include "Engine/DataTable.h"
#include "LightScenarioRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FLightScenarioRowHandle : public FDataTableRowHandle {
    GENERATED_BODY()
public:
    ROBOQUEST_API FLightScenarioRowHandle();
};

