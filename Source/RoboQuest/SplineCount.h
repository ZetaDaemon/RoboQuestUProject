#pragma once
#include "CoreMinimal.h"
#include "ECountableSplineType.h"
#include "SplineCount.generated.h"

USTRUCT(BlueprintType)
struct FSplineCount {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECountableSplineType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Count;
    
    ROBOQUEST_API FSplineCount();
};

