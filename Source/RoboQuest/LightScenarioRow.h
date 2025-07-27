#pragma once
#include "CoreMinimal.h"
#include "LightScenarioRow.generated.h"

class AALightPostProcess;

USTRUCT(BlueprintType)
struct FLightScenarioRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AALightPostProcess> PostProcess;
    
    ROBOQUEST_API FLightScenarioRow();
};

