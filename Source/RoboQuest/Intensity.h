#pragma once
#include "CoreMinimal.h"
#include "Intensity.generated.h"

USTRUCT(BlueprintType)
struct FIntensity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Intensities;
    
    ROBOQUEST_API FIntensity();
};

