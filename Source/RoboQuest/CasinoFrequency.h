#pragma once
#include "CoreMinimal.h"
#include "CasinoFrequency.generated.h"

USTRUCT(BlueprintType)
struct FCasinoFrequency {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Frequency[5];
    
    ROBOQUEST_API FCasinoFrequency();
};

