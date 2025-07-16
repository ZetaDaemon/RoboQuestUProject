#pragma once
#include "CoreMinimal.h"
#include "StatValues.generated.h"

USTRUCT(BlueprintType)
struct FStatValues {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float currentValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxValue;
    
    ROBOQUEST_API FStatValues();
};

