#pragma once
#include "CoreMinimal.h"
#include "IceMetric.generated.h"

USTRUCT(BlueprintType)
struct FIceMetric {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    ROBOQUEST_API FIceMetric();
};

