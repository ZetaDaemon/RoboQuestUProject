#pragma once
#include "CoreMinimal.h"
#include "HapticData.generated.h"

USTRUCT(BlueprintType)
struct FHapticData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    ROBOQUEST_API FHapticData();
};

