#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "LightScenarioRow.h"
#include "LightScenario.generated.h"

USTRUCT(BlueprintType)
struct FLightScenario : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightScenarioRow LightScenario;
    
    ROBOQUEST_API FLightScenario();
};

